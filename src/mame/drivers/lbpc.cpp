// license:BSD-3-Clause
// copyright-holders:AJR
/****************************************************************************

    Skeleton driver for Ampro Little Board/PC.

    This is unusual among PC/XT-compatible machines in that many standard
    peripheral functions, including the interrupt and refresh controllers,
    are integrated into the V40 CPU itself, with some software assistance
    to compensate for DMAC incompatibilities. Two Vadem SDIP64 ASICs and a
    standard FDC and UART provide most other PC-like hardware features. The
    BIOS also supports the onboard SCSI controller.

****************************************************************************/

#include "emu.h"
//#include "bus/isa/isa.h"
#include "bus/nscsi/devices.h"
#include "cpu/nec/v5x.h"
#include "machine/ins8250.h"
#include "machine/ncr5380n.h"
#include "machine/upd765.h"

class lbpc_state : public driver_device
{
public:
	lbpc_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag)
		, m_maincpu(*this, "maincpu")
	{
	}

	void lbpc(machine_config &config);

private:
	void mem_map(address_map &map);
	void io_map(address_map &map);

	required_device<v40_device> m_maincpu;
};


void lbpc_state::mem_map(address_map &map)
{
	map(0x00000, 0x9ffff).ram(); // 256K, 512K or 768K DRAM
	// 0xE0000–0xEFFFF: empty socket
	// 0xF0000-0xF7FFF: empty socket
	map(0xf8000, 0xfffff).rom().region("bios", 0);
}

void lbpc_state::io_map(address_map &map)
{
	map(0x0330, 0x0337).rw("scsi:7:ncr", FUNC(ncr53c80_device::read), FUNC(ncr53c80_device::write));
	map(0x0370, 0x0377).m("fdc", FUNC(wd37c65c_device::map));
	map(0x03f8, 0x03ff).rw("com", FUNC(ins8250_device::ins8250_r), FUNC(ins8250_device::ins8250_w));
}


static INPUT_PORTS_START(lbpc)
INPUT_PORTS_END


void lbpc_state::lbpc(machine_config &config)
{
	V40(config, m_maincpu, 14.318181_MHz_XTAL / 2);
	m_maincpu->set_addrmap(AS_PROGRAM, &lbpc_state::mem_map);
	m_maincpu->set_addrmap(AS_IO, &lbpc_state::io_map);
	m_maincpu->set_clk<0>(14.318181_MHz_XTAL / 12); // TCLK input generated by ASIC1
	m_maincpu->set_clk<1>(14.318181_MHz_XTAL / 12);
	m_maincpu->set_clk<2>(14.318181_MHz_XTAL / 12);
	m_maincpu->in_ior_cb<3>().set("scsi:7:ncr", FUNC(ncr53c80_device::dma_r));
	m_maincpu->out_iow_cb<3>().set("scsi:7:ncr", FUNC(ncr53c80_device::dma_w));

	INS8250(config, "com", 1.8432_MHz_XTAL); // INS8250AV

	WD37C65C(config, "fdc", 16_MHz_XTAL, 9.6_MHz_XTAL); // WD37C65BJM

	NSCSI_BUS(config, "scsi");
	NSCSI_CONNECTOR(config, "scsi:0", default_scsi_devices, nullptr);
	NSCSI_CONNECTOR(config, "scsi:1", default_scsi_devices, nullptr);
	NSCSI_CONNECTOR(config, "scsi:2", default_scsi_devices, nullptr);
	NSCSI_CONNECTOR(config, "scsi:3", default_scsi_devices, nullptr);
	NSCSI_CONNECTOR(config, "scsi:4", default_scsi_devices, nullptr);
	NSCSI_CONNECTOR(config, "scsi:5", default_scsi_devices, nullptr);
	NSCSI_CONNECTOR(config, "scsi:6", default_scsi_devices, nullptr);
	NSCSI_CONNECTOR(config, "scsi:7").option_set("ncr", NCR53C80).machine_config([this] (device_t *device) {
		downcast<ncr5380n_device &>(*device).drq_handler().set(m_maincpu, FUNC(v40_device::dreq_w<3>));
	});
}


ROM_START(lbpc)
	ROM_REGION(0x8000, "bios", 0)
	ROM_LOAD("lbpc-bio.rom", 0x0000, 0x8000, CRC(47bddf8b) SHA1(8a04fe34502f9f3bfe1e233762bbd5bbdd1c455d)) // "03/08/89"
ROM_END


COMP(1989, lbpc, 0, 0, lbpc, lbpc, lbpc_state, empty_init, "Ampro Computers", "Little Board/PC", MACHINE_IS_SKELETON)
