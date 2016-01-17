// license:BSD-3-Clause
// copyright-holders:David Haywood

#include "emu.h"
#include "cpu/m6502/m6502.h"

class deco_cpu7_device : public m6502_device {
public:
	deco_cpu7_device(const machine_config &mconfig, std::string tag, device_t *owner, UINT32 clock);

protected:
	class mi_decrypt : public mi_default_normal {
	public:
		bool had_written;

		virtual ~mi_decrypt() {}
		virtual UINT8 read_sync(UINT16 adr) override;
		virtual void write(UINT16 adr, UINT8 val) override;
	};

	virtual void device_start() override;
	virtual void device_reset() override;

};

static const device_type DECO_CPU7 = &device_creator<deco_cpu7_device>;
