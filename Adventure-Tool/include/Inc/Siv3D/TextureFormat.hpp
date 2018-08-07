﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (C) 2008-2016 Ryo Suzuki
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once

namespace s3d
{
	enum class TextureFormat
	{
		Unknown	                    = 0,
		R32G32B32A32_Typeless       = 1,
		R32G32B32A32_Float          = 2,
		R32G32B32A32_Uint           = 3,
		R32G32B32A32_Sint           = 4,
		R32G32B32_Typeless          = 5,
		R32G32B32_Float             = 6,
		R32G32B32_Uint              = 7,
		R32G32B32_Sint              = 8,
		R16G16B16A16_Typeless       = 9,
		R16G16B16A16_Float          = 10,
		R16G16B16A16_Unorm          = 11,
		R16G16B16A16_Uint           = 12,
		R16G16B16A16_Snorm          = 13,
		R16G16B16A16_Sint           = 14,
		R32G32_Typeless             = 15,
		R32G32_Float                = 16,
		R32G32_Uint                 = 17,
		R32G32_Sint                 = 18,
		R32G8X24_Typeless           = 19,
		D32_Float_S8X24_Uint        = 20,
		R32_Float_X8X24_Typeless    = 21,
		X32_Typeless_G8X24_Uint     = 22,
		R10G10B10A2_Typeless        = 23,
		R10G10B10A2_Unorm           = 24,
		R10G10B10A2_Uint            = 25,
		R11G11B10_Float             = 26,
		R8G8B8A8_Typeless           = 27,
		R8G8B8A8_Unorm              = 28,
		R8G8B8A8_Unorm_SRGB         = 29,
		R8G8B8A8_Uint               = 30,
		R8G8B8A8_Snorm              = 31,
		R8G8B8A8_Sint               = 32,
		R16G16_Typeless             = 33,
		R16G16_Float                = 34,
		R16G16_Unorm                = 35,
		R16G16_Uint                 = 36,
		R16G16_Snorm                = 37,
		R16G16_Sint                 = 38,
		R32_Typeless                = 39,
		D32_Float                   = 40,
		R32_Float                   = 41,
		R32_Uint                    = 42,
		R32_Sint                    = 43,
		R24G8_Typeless              = 44,
		D24_Unorm_S8_Uint           = 45,
		R24_Unorm_X8_Typeless       = 46,
		X24_Typeless_G8_Uint        = 47,
		R8G8_Typeless               = 48,
		R8G8_Unorm                  = 49,
		R8G8_Uint                   = 50,
		R8G8_Snorm                  = 51,
		R8G8_Sint                   = 52,
		R16_Typeless                = 53,
		R16_Float                   = 54,
		D16_Unorm                   = 55,
		R16_Unorm                   = 56,
		R16_Uint                    = 57,
		R16_Snorm                   = 58,
		R16_Sint                    = 59,
		R8_Typeless                 = 60,
		R8_Unorm                    = 61,
		R8_Uint                     = 62,
		R8_Snorm                    = 63,
		R8_Sint                     = 64,
		A8_Unorm                    = 65,
		R1_Unorm                    = 66,
		R9G9B9E5_SharedExp          = 67,
		R8G8_B8G8_Unorm             = 68,
		G8R8_G8B8_Unorm             = 69,
		BC1_Typeless                = 70,
		BC1_Unorm                   = 71,
		BC1_Unorm_SRGB              = 72,
		BC2_Typeless                = 73,
		BC2_Unorm                   = 74,
		BC2_Unorm_SRGB              = 75,
		BC3_Typeless                = 76,
		BC3_Unorm                   = 77,
		BC3_Unorm_SRGB              = 78,
		BC4_Typeless                = 79,
		BC4_Unorm                   = 80,
		BC4_Snorm                   = 81,
		BC5_Typeless                = 82,
		BC5_Unorm                   = 83,
		BC5_Snorm                   = 84,
		B5G6R5_Unorm                = 85,
		B5G5R5A1_Unorm              = 86,
		B8G8R8A8_Unorm              = 87,
		B8G8R8X8_Unorm              = 88,
		R10G10B10_XR_BIAS_A2_Unorm  = 89,
		B8G8R8A8_Typeless           = 90,
		B8G8R8A8_Unorm_SRGB         = 91,
		B8G8R8X8_Typeless           = 92,
		B8G8R8X8_Unorm_SRGB         = 93,
		BC6H_Typeless               = 94,
		BC6H_UF16                   = 95,
		BC6H_SF16                   = 96,
		BC7_Typeless                = 97,
		BC7_Unorm                   = 98,
		BC7_Unorm_SRGB              = 99,
		AYUV                        = 100,
		Y410                        = 101,
		Y416                        = 102,
		NV12                        = 103,
		P010                        = 104,
		P016                        = 105,
		YUV420_Opaque				= 106,
		YUY2                        = 107,
		Y210                        = 108,
		Y216                        = 109,
		NV11                        = 110,
		AI44                        = 111,
		IA44                        = 112,
		P8                          = 113,
		A8P8                        = 114,
		B4G4R4A4_Unorm              = 115,
	};
}
