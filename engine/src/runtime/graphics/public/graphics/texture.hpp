#pragma once

namespace openworld
{
	class render_system;
	class render_context;

	class texture :
		public graphics_resource,
		public shader_resource
	{
        OPENWORLD_DELETE_COPY_OPERATORS(texture);

	public:
        texture() {}
		virtual ~texture() {}

		virtual size_t mip_count() const = 0;
		virtual surface_format format() const = 0;
		virtual resource_usage usage() const = 0;
		virtual texture_dimension dimension() const = 0;

        static constexpr size_t calculate_mip_map_count(size_t width)
        {
            return calculate_mip_map_count(width, 1, 1);
        }

        static constexpr size_t calculate_mip_map_count(size_t width, size_t height)
        {
            return calculate_mip_map_count(width, height, 1);
        }

        static constexpr size_t calculate_mip_map_count(size_t width, size_t height, size_t depth)
        {
            size_t max = std::max(std::max(width, height), depth);

            if (max == 0)
            {
                return 0;
            }

            return 1 + static_cast<size_t>(std::floor((std::log(max) / std::log(2))));
        }

        static constexpr void calculate_mip_level_dimensions(size_t mip_level, size_t& width)
        {
            size_t height = 1;
            size_t depth = 1;
            calculate_mip_level_dimensions(mip_level, width, height, depth);
        }

        static constexpr void calculate_mip_level_dimensions(size_t mip_level, size_t& width, size_t& height)
        {
            size_t depth = 1;
            calculate_mip_level_dimensions(mip_level, width, height, depth);
        }

        static constexpr void calculate_mip_level_dimensions(size_t mip_level, size_t& width, size_t& height, size_t& depth)
        {
            if (mip_level < 0)
            {
                return;
            }

            width = std::max(1ULL, width >> mip_level);
            height = std::max(1ULL, height >> mip_level);
            depth = std::max(1ULL, depth >> mip_level);
        }

        static constexpr size_t calculate_mip_level_size_in_bytes(size_t mip_level, size_t width, surface_format format)
        {
            if (mip_level < 0 || is_compressed_format(format))
            {
                return 0;
            }

            calculate_mip_level_dimensions(mip_level, width);

            size_t format_sz = 0;
            return calculate_region_size_in_bytes(format, width, format_sz);
        }

        static constexpr size_t calculate_mip_level_size_in_bytes(size_t mipLevel, size_t width, size_t height, surface_format format)
        {
            return calculate_mip_level_size_in_bytes(mipLevel, width, height, 1, format);
        }

        static constexpr size_t calculate_mip_level_size_in_bytes(size_t mipLevel, size_t width, size_t height, size_t depth, surface_format format)
        {
            if (mipLevel < 0)
            {
                return 0;
            }

            calculate_mip_level_dimensions(mipLevel, width, height, depth);

            size_t format_sz = 0;
            return calculate_region_size_in_bytes(format, width, height, depth, format_sz);
        }

        static constexpr size_t calculate_region_size_in_bytes(surface_format format, size_t& width, size_t& format_sz)
        {
            if (is_compressed_format(format))
            {
                format_sz = 0;
                return 0;
            }

            format_sz = format_size(format);
            return width * format_sz;
        }

        static constexpr size_t calculate_region_size_in_bytes(surface_format format, size_t& width, size_t& height, size_t& format_sz)
        {
            if (is_compressed_format(format))
            {
                return calculate_compressed_dimensions(format, width, height, 1, format_sz);
            }
            else
            {
                format_sz = format_size(format);
                return width * height * format_sz;
            }
        }

        static constexpr size_t calculate_region_size_in_bytes(surface_format format, size_t& width, size_t& height, size_t& depth, size_t& format_sz)
        {
            if (is_compressed_format(format))
            {
                return calculate_compressed_dimensions(format, width, height, depth, format_sz);
            }
            else
            {
                format_sz = format_size(format);
                return width * height * depth * format_sz;
            }
        }

        static constexpr size_t calculate_compressed_dimensions(surface_format format, size_t& width, size_t& height, size_t& format_sz)
        {
            return calculate_compressed_dimensions(format, width, height, 1, format_sz);
        }

        static constexpr size_t calculate_compressed_dimensions(surface_format format, size_t& width, size_t& height, size_t depth, size_t& format_sz)
        {
            format_sz = 0;

            if (format == surface_format::dxt1 || format == surface_format::dxt3 || format == surface_format::dxt5)
            {
                width = std::max(1ULL, (width + 3) / 4);
                height = std::max(1ULL, (height + 3) / 4);

                format_sz = (format == surface_format::dxt1) ? 8 : 16;

                return width * height * depth * format_sz;
            }

            return 0;
        }

        static constexpr size_t calculate_sub_resource_index(size_t array_slice, size_t mip_slice, size_t num_mip_levels)
        {
            return (num_mip_levels * array_slice) + mip_slice;
        }

        //public static bool GenerateMipMaps(Texture texture)
        //{
        //    if (texture == null)
        //    {
        //        return false;
        //    }

        //    IRenderSystem renderSystem = texture.RenderSystem;
        //    IGenerateMipMapsExtension genMipMaps = renderSystem.ImmediateContext.GetExtension<IGenerateMipMapsExtension>();

        //    if (genMipMaps == null)
        //    {
        //        return false;
        //    }

        //    return genMipMaps.GenerateMipMaps(texture);
        //}

        //public static Texture From(TextureData texData, IRenderSystem renderSystem, ResourceUsage resourceUsage = ResourceUsage.Immutable)
        //{
        //    if (!texData.Validate() || renderSystem == null)
        //    {
        //        return null;
        //    }

        //    // Every mipchain will have the same # of mip levels at this point, if it passed validation
        //    int mipCount = texData.MipChains[0].Count;
        //    int arrayCount = texData.MipChains.Count;

        //    IDataBuffer[] surfaces = GetFlattenSurfaceArray(texData.MipChains);
        //    bool genMipMaps = mipCount > 1;

        //    switch (texData.TextureType)
        //    {
        //    case TextureType.Texture1D:
        //        return new Texture1D(renderSystem, (int)texData.Width, genMipMaps, texData.Format, resourceUsage, surfaces);
        //    case TextureType.Texture1DArray:
        //        return new Texture1DArray(renderSystem, (int)texData.Width, arrayCount, genMipMaps, texData.Format, resourceUsage, surfaces);
        //    case TextureType.Texture2D:
        //        return new Texture2D(renderSystem, (int)texData.Width, (int)texData.Height, genMipMaps, texData.Format, resourceUsage, surfaces);
        //    case TextureType.Texture2DArray:
        //        return new Texture2DArray(renderSystem, (int)texData.Width, (int)texData.Height, arrayCount, genMipMaps, texData.Format, resourceUsage, surfaces);
        //    case TextureType.Texture3D:
        //        return new Texture3D(renderSystem, (int)texData.Width, (int)texData.Height, (int)texData.Depth, genMipMaps, texData.Format, resourceUsage, surfaces);
        //    case TextureType.TextureCube:
        //        return new TextureCube(renderSystem, (int)texData.Width, genMipMaps, texData.Format, resourceUsage, surfaces);
        //    default:
        //        return null;
        //    }
        //}

        //private static IDataBuffer[] GetFlattenSurfaceArray(IList<TextureData.MipChain> data)
        //{
        //    int arrayCount = data.Count;
        //    int mipCount = data[0].Count;

        //    IDataBuffer[] surfaces = new IDataBuffer[mipCount * arrayCount];
        //    int index = 0;

        //    for (int arraySlice = 0; arraySlice < arrayCount; arraySlice++)
        //    {
        //        TextureData.MipChain mips = data[arraySlice];
        //        System.Diagnostics.Debug.Assert(mips.Count == mipCount);

        //        for (int i = 0; i < mipCount; i++)
        //        {
        //            surfaces[index++] = mips[i].Data;
        //        }
        //    }

        //    return surfaces;
        //}

        //protected void CheckBlockCompressionMinimumSize(SurfaceFormat format, ref int size)
        //{
        //    //Block compression formats need to be in multiples of 4, which means the minimum size is 4. Textures that are technically 4x4, 2x2, 1x1 all are the same
        //    //size. Most likely we'll see these as the lowest levels of the mipchain.
        //    if (format.IsCompressedFormat())
        //    {
        //        //Ensure minimum is 4
        //        size = Math.Max(4, size);

        //        //Ensure dimensions are multiples of 4
        //        if ((size % 4) != 0)
        //        {
        //            throw GraphicsExceptionHelper.NewBlockCompressionMultipleOfFourException(format);
        //        }
        //    }
        //}

        //protected void CheckBlockCompressionMinimumSize(SurfaceFormat format, ref int width, ref int height)
        //{
        //    //Block compression formats need to be in multiples of 4, which means the minimum size is 4. Textures that are technically 4x4, 2x2, 1x1 all are the same
        //    //size. Most likely we'll see these as the lowest levels of the mipchain.
        //    if (format.IsCompressedFormat())
        //    {
        //        //Ensure minimum is 4
        //        width = Math.Max(4, width);
        //        height = Math.Max(4, height);

        //        //Ensure dimensions are multiples of 4
        //        if ((width % 4) != 0 || (height % 4) != 0)
        //        {
        //            throw GraphicsExceptionHelper.NewBlockCompressionMultipleOfFourException(format);
        //        }
        //    }
        //}
	};
}
