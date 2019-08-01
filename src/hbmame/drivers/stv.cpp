// license:BSD-3-Clause
// copyright-holders:Robbbert
#include "../mame/drivers/stv.cpp"

//PSmame (c) gaston90 used with permission

 /********************************************
      Proyecto Shadows Mame Build Plus
**********************************************/

/***********
 Golden Axe
************/

ROM_START( gaxeduels01 )
	STV_BIOS
	ROM_REGION32_BE( 0x3000000, "cart", ROMREGION_ERASE00 )
	ROM_LOAD16_BYTE( "epr17766_ps01.13",               0x0000001, 0x0080000, CRC(e9728569) SHA1(fc7cfc982648d0035c1c69d2fda26142cc98f231) )
	ROM_RELOAD( 0x0100001, 0x0080000 )
	ROM_RELOAD_PLAIN ( 0x0200000, 0x0080000 )
	ROM_RELOAD_PLAIN ( 0x0300000, 0x0080000 )
	ROM_LOAD16_WORD_SWAP( "mpr17768.2",    0x0400000, 0x0400000, CRC(d6808a7d) SHA1(83a97bbe1160cb45b3bdcbde8adc0d9bae5ded60) )
	ROM_LOAD16_WORD_SWAP( "mpr17769.3",    0x0800000, 0x0400000, CRC(3471dd35) SHA1(24febddfe70984cebc0e6948ad718e0e6957fa82) )
	ROM_LOAD16_WORD_SWAP( "mpr17770.4",    0x0c00000, 0x0400000, CRC(06978a00) SHA1(a8d1333a9f4322e28b23724937f595805315b136) )
	ROM_LOAD16_WORD_SWAP( "mpr17771.5",    0x1000000, 0x0400000, CRC(aea2ea3b) SHA1(2fbe3e10d3f5a3b3099a7ed5b38b93b6e22e19b8) )
	ROM_LOAD16_WORD_SWAP( "mpr17772.6",    0x1400000, 0x0400000, CRC(b3dc0e75) SHA1(fbe2790c84466d186ea3e9d41edfcb7afaf54bea) )
	ROM_LOAD16_WORD_SWAP( "mpr17767.1",    0x1800000, 0x0400000, CRC(9ba1e7b1) SHA1(f297c3697d2e8ba4476d672267163f91f371b362) )
ROM_END

/****************
 Groove on Fight
******************/

ROM_START( groovefs01 )
	STV_BIOS
	ROM_REGION32_BE( 0x3000000, "cart", ROMREGION_ERASE00 )
	ROM_LOAD16_WORD_SWAP( "mpr19820_ps01.7",    0x0200000, 0x0100000, CRC(f8f025ab) SHA1(d8e629b71214bb6754d9e9854b529d38755d3e1c) )
	ROM_LOAD16_WORD_SWAP( "mpr19815.2",    0x0400000, 0x0400000, CRC(1b9b14e6) SHA1(b1828c520cb108e2927a23273ebd2939dca52304) )
	ROM_LOAD16_WORD_SWAP( "mpr19816.3",    0x0800000, 0x0400000, CRC(83f5731c) SHA1(2f645737f945c59a1a2fabf3b21a761be9e8c8a6) )
	ROM_LOAD16_WORD_SWAP( "mpr19817.4",    0x0c00000, 0x0400000, CRC(525bd6c7) SHA1(2db2501177fb0b44d0fad2054eddf356c4ea08f2) )
	ROM_LOAD16_WORD_SWAP( "mpr19818.5",    0x1000000, 0x0400000, CRC(66723ba8) SHA1(0a8379e46a8f8cab11befeadd9abdf59dba68e27) )
	ROM_LOAD16_WORD_SWAP( "mpr19819.6",    0x1400000, 0x0400000, CRC(ee8c55f4) SHA1(f6d86b2c2ab43ec5baefb8ccc25e11af4d82712d) )
	ROM_LOAD16_WORD_SWAP( "mpr19814.1",    0x1800000, 0x0400000, CRC(8f20e9f7) SHA1(30ff5ad0427208e7265cb996e870c4dc0fbbf7d2) )
	ROM_LOAD16_WORD_SWAP( "mpr19821.8",    0x1c00000, 0x0400000, CRC(f69a76e6) SHA1(b7e41f34d8b787bf1b4d587e5d8bddb241c043a8) )
	ROM_LOAD16_WORD_SWAP( "mpr19822.9",    0x2000000, 0x0200000, CRC(5e8c4b5f) SHA1(1d146fbe3d0bfa68993135ba94ef18081ab65d31) )
ROM_END

/***********
 Golden Axe
************/

ROM_START( suikoenbs01 )
	STV_BIOS
	ROM_REGION32_BE( 0x3000000, "cart", ROMREGION_ERASE00 )
	ROM_LOAD16_BYTE( "fpr17834_ps01.13",               0x0000001, 0x0100000, CRC(f526855b) SHA1(b742fac38c8c480f4825d3bb904da9ba413d2442) )
	ROM_RELOAD_PLAIN( 0x0200000, 0x0100000)
	ROM_RELOAD_PLAIN( 0x0300000, 0x0100000)
	ROM_LOAD16_WORD_SWAP( "mpr17836.2",    0x0400000, 0x0400000, CRC(55e9642d) SHA1(5198291cd1dce0398eb47760db2c19eae99273b0) )
	ROM_LOAD16_WORD_SWAP( "mpr17837.3",    0x0800000, 0x0400000, CRC(13d1e667) SHA1(cd513ceb33cc20032090113b61227638cf3b3998) )
	ROM_LOAD16_WORD_SWAP( "mpr17838.4",    0x0c00000, 0x0400000, CRC(f9e70032) SHA1(8efdbcce01bdf77acfdb293545c59bf224a9c7d2) )
	ROM_LOAD16_WORD_SWAP( "mpr17839.5",    0x1000000, 0x0400000, CRC(1b2762c5) SHA1(5c7d5fc8a4705249a5b0ea64d51dc3dc95d723f5) )
	ROM_LOAD16_WORD_SWAP( "mpr17840.6",    0x1400000, 0x0400000, CRC(0fd4c857) SHA1(42caf22716e834d59e60d45c24f51d95734e63ae) )
	ROM_LOAD16_WORD_SWAP( "mpr17835.1",    0x1800000, 0x0400000, CRC(77f5cb43) SHA1(a4f54bc08d73a56caee5b26bea06360568655bd7) )
	ROM_LOAD16_WORD_SWAP( "mpr17841.8",    0x1c00000, 0x0400000, CRC(f48beffc) SHA1(92f1730a206f4a0abf7fb0ee1210e083a464ad70) )
	ROM_LOAD16_WORD_SWAP( "mpr17842.9",    0x2000000, 0x0400000, CRC(ac8deed7) SHA1(370eb2216b8080d3ddadbd32804db63c4ebac76f) )
ROM_END

/*    YEAR  NAME            PARENT    MACHINE        INPUT       INIT             MONITOR COMPANY                 FULLNAME FLAGS */
// Golden Axe
GAME( 1994, gaxeduels01,  gaxeduel, stv,      stv6b,    stv_state,   init_gaxeduel,   ROT0,   "yumeji",                         "Golden Axe (Enable Hidden Characters)", MACHINE_IMPERFECT_SOUND | MACHINE_IMPERFECT_GRAPHICS)
// Groove on Fight
GAME( 1997, groovefs01,   groovef,  stv,      stv6b,    stv_state,   init_groovef,    ROT0,   "yumeji",                        "Groove on Fight (Enable Hidden Characters)", MACHINE_IMPERFECT_SOUND | MACHINE_IMPERFECT_GRAPHICS )
// Suiko Enbu / Outlaws of the Lost Dynasty
GAME( 1995, suikoenbs01,  suikoenb, stv,      stv6b,    stv_state,   init_suikoenb,   ROT0,   "yumeji",                    "Suiko Enbu / Outlaws of the Lost Dynasty (Enable Hidden Characters)", MACHINE_IMPERFECT_SOUND | MACHINE_IMPERFECT_GRAPHICS )



