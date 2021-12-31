#pragma once

namespace openworld
{
    class shader_pipeline_stage
    {
        virtual ~shader_pipeline_stage() = 0 {}

        virtual size_t maximum_sampler_slots() = 0;
        virtual size_t maximum_resource_slots() = 0;
        virtual shader_stage shader_type() = 0;

        //void SetSampler(SamplerState sampler);
        //void SetSampler(int slotIndex, SamplerState sampler);
        //void SetSamplers(params SamplerState[] samplers);
        //void SetSamplers(int startSlotIndex, params SamplerState[] samplers);
        //void SetShaderResource(IShaderResource resource);
        //void SetShaderResource(int slotIndex, IShaderResource resource);
        //void SetShaderResources(params IShaderResource[] resources);
        //void SetShaderResources(int startSlotIndex, params IShaderResource[] resources);
        //SamplerState[] GetSamplers(int startSlotIndex, int count);
        //IShaderResource[] GetShaderResources(int startSlotIndex, int count);
    };
}