#pragma once

#include "core/mesh.hpp"

#include "opengl/shader.hpp"
#include "opengl/texture.hpp"

namespace graphics
{
    class ModelRenderer
    {
    public:
        void begin()    const;

        void draw(const core::Mesh* mesh, const math::mat4& matrix, const opengl::Texture* texture) const;
        void draw(const core::Mesh* mesh, const math::mat4& matrix, const math::rgb& color)         const;

        void attach(opengl::Buffer* buffer);
        void attach(opengl::Shader* shader);

    private:
        opengl::Buffer* _buffer { };
        opengl::Shader* _shader { };
    };
}