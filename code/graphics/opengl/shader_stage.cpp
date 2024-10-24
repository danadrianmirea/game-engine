#include "shader_stage.hpp"
#include "functions.hpp"
#include "macros.hpp"

namespace engine::gl
{
    ShaderStage::ShaderStage(const uint32_t type)
        : type_ { type }
    {
    }

    void ShaderStage::create()
    {
        handle_ = glCreateShader(type_);
    }

    void ShaderStage::destroy()
    {
        glDeleteShader(handle_);
    }

    void ShaderStage::source(const std::vector<char>& source) const
    {
        glShaderBinary(1, &handle_, shader_binary, source.data(), static_cast<int32_t>(source.size()));
        glSpecializeShader(handle_, "main", 0, nullptr, nullptr);
    }
}