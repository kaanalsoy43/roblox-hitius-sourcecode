#pragma once

namespace RBX {

enum PartMaterial
{
	PLASTIC_MATERIAL	= 0x0100,
	SMOOTH_PLASTIC_MATERIAL	= 0x0110,
	NEON_MATERIAL		= 0x0120,
	WOOD_MATERIAL		= 0x0200,
    WOODPLANKS_MATERIAL = 0x0210,
	MARBLE_MATERIAL		= 0x0310,
	SLATE_MATERIAL		= 0x0320,
	CONCRETE_MATERIAL	= 0x0330,
	GRANITE_MATERIAL	= 0x0340,
	BRICK_MATERIAL	    = 0x0350,
	PEBBLE_MATERIAL	    = 0x0360,
    COBBLESTONE_MATERIAL= 0x0370,
    ROCK_MATERIAL		= 0x0380,
    SANDSTONE_MATERIAL	= 0x0390,
    BASALT_MATERIAL		= 0x0314,
    CRACKED_LAVA_MATERIAL = 0x0324,
	RUST_MATERIAL       = 0x0410,
	DIAMONDPLATE_MATERIAL = 0x0420,
	ALUMINUM_MATERIAL	= 0x0430,
    METAL_MATERIAL      = 0x0440,
	GRASS_MATERIAL		= 0x0500,
	SAND_MATERIAL		= 0x0510,
	FABRIC_MATERIAL		= 0x0520,
	SNOW_MATERIAL		= 0x0530,
	MUD_MATERIAL		= 0x0540,
	GROUND_MATERIAL		= 0x0550,
	ICE_MATERIAL		= 0x0600,
	GLACIER_MATERIAL	= 0x0610,
	AIR_MATERIAL		= 0x0700,
	WATER_MATERIAL		= 0x0800,
	LEGACY_MATERIAL		= 0xFFFF, // should not be serialized
};

}