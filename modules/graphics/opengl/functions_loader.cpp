#include "functions_loader.hpp"

namespace opengl
{
    void FunctionsLoader::init_core()
    {
        const auto   instance = LoadLibrary("opengl32.dll");

        if (instance == nullptr)
        {
            std::exit(EXIT_FAILURE);
        }

        glClear        = reinterpret_cast<PFNGLCLEARPROC>(GetProcAddress(instance,        "glClear"));
        glClearColor   = reinterpret_cast<PFNGLCLEARCOLORPROC>(GetProcAddress(instance,   "glClearColor"));
        glEnable       = reinterpret_cast<PFNGLENABLEPROC>(GetProcAddress(instance,       "glEnable"));
        glDisable      = reinterpret_cast<PFNGLDISABLEPROC>(GetProcAddress(instance,      "glDisable"));
        glDrawArrays   = reinterpret_cast<PFNGLDRAWARRAYSPROC>(GetProcAddress(instance,   "glDrawArrays"));
        glDrawElements = reinterpret_cast<PFNGLDRAWELEMENTSPROC>(GetProcAddress(instance, "glDrawElements"));
        glPolygonMode  = reinterpret_cast<PFNGLPOLYGONMODEPROC>(GetProcAddress(instance,  "glPolygonMode"));
        glViewport     = reinterpret_cast<PFNGLVIEWPORTPROC>(GetProcAddress(instance,     "glViewport"));

        FreeLibrary(instance);
    }

    void FunctionsLoader::init_extensions()
    {
        #pragma region Buffers

        glCreateBuffers      = reinterpret_cast<PFNGLCREATEBUFFERSPROC>(wglGetProcAddress("glCreateBuffers"));
        glDeleteBuffers      = reinterpret_cast<PFNGLDELETEBUFFERSPROC>(wglGetProcAddress("glDeleteBuffers"));
        glBindBufferBase     = reinterpret_cast<PFNGLBINDBUFFERBASEPROC>(wglGetProcAddress("glBindBufferBase"));
        glNamedBufferData    = reinterpret_cast<PFNGLNAMEDBUFFERDATAPROC>(wglGetProcAddress("glNamedBufferData"));
        glNamedBufferSubData = reinterpret_cast<PFNGLNAMEDBUFFERSUBDATAPROC>(wglGetProcAddress("glNamedBufferSubData"));

        #pragma endregion
        #pragma region VertexArray

        glCreateVertexArrays       = reinterpret_cast<PFNGLCREATEVERTEXARRAYSPROC>(wglGetProcAddress("glCreateVertexArrays"));
        glDeleteVertexArrays       = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(wglGetProcAddress("glDeleteVertexArrays"));
        glBindVertexArray          = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(wglGetProcAddress("glBindVertexArray"));
        glVertexArrayVertexBuffer  = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERPROC>(wglGetProcAddress("glVertexArrayVertexBuffer"));
        glVertexArrayElementBuffer = reinterpret_cast<PFNGLVERTEXARRAYELEMENTBUFFERPROC>(wglGetProcAddress("glVertexArrayElementBuffer"));
        glVertexArrayAttribFormat  = reinterpret_cast<PFNGLVERTEXARRAYATTRIBFORMATPROC>(wglGetProcAddress("glVertexArrayAttribFormat"));
        glVertexArrayAttribBinding = reinterpret_cast<PFNGLVERTEXARRATATTRIBBINDINGPROC>(wglGetProcAddress("glVertexArrayAttribBinding"));
        glEnableVertexArrayAttrib  = reinterpret_cast<PFNGLENABLEVERTEXARRAYATTRIPROC>(wglGetProcAddress("glEnableVertexArrayAttrib"));

        #pragma endregion
        #pragma region ShaderStage

        glCreateShader     = reinterpret_cast<PFNGLCREATESHADERPROC>(wglGetProcAddress("glCreateShader"));
        glDeleteShader     = reinterpret_cast<PFNGLDELETESHADERPROC>(wglGetProcAddress("glDeleteShader"));
        glShaderBinary     = reinterpret_cast<PFNGLSHADERBINARYPROC>(wglGetProcAddress("glShaderBinary"));
        glSpecializeShader = reinterpret_cast<PFNGLSPECIALIZESHADERPROC>(wglGetProcAddress("glSpecializeShader"));

        #pragma endregion
        #pragma region ShaderProgram

        glCreateProgram = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(wglGetProcAddress("glCreateProgram"));
        glAttachShader  = reinterpret_cast<PFNGLATTACHSHADERPROC>(wglGetProcAddress("glAttachShader"));
        glLinkProgram   = reinterpret_cast<PFNGLLINKPROGRAMPROC>(wglGetProcAddress("glLinkProgram"));
        glUseProgram    = reinterpret_cast<PFNGLUSEPROGRAMPROC>(wglGetProcAddress("glUseProgram"));
        glDeleteProgram = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(wglGetProcAddress("glDeleteProgram"));

        glProgramUniformMatrix4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>(wglGetProcAddress("glProgramUniformMatrix4fv"));

        #pragma endregion
        #pragma region Textures

        glCreateTextures        = reinterpret_cast<PFNGLCREATETEXTURESPROC>(wglGetProcAddress("glCreateTextures"));
        glDeleteTextures        = reinterpret_cast<PFNGLDELETETEXTURESPROC>(wglGetProcAddress("glDeleteTextures"));
        glBindTextureUnit       = reinterpret_cast<PFNGLBINDTEXTUREUNITPROC>(wglGetProcAddress("glBindTextureUnit"));
        glTextureStorage2D      = reinterpret_cast<PFNGLTEXTURESTORAGE2DPROC>(wglGetProcAddress("glTextureStorage2D"));
        glTextureSubImage2D     = reinterpret_cast<PFNGLTEXTURESUBIMAGE2DPROC>(wglGetProcAddress("glTextureSubImage2D"));
        glGenerateTextureMipmap = reinterpret_cast<PFNGLGENERATETEXTUREMIPMAPPROC>(wglGetProcAddress("glGenerateTextureMipmap"));

        #pragma endregion
        #pragma region Samplers

        glCreateSamplers    = reinterpret_cast<PFNGLCREATESAMPLERSPROC>(wglGetProcAddress("glCreateSamplers"));
        glDeleteSamplers    = reinterpret_cast<PFNGLDELETESAMPLERSPROC>(wglGetProcAddress("glDeleteSamplers"));
        glBindSampler       = reinterpret_cast<PFNGLBINDSAMPLERPROC>(wglGetProcAddress("glBindSampler"));
        glSamplerParameteri = reinterpret_cast<PFNGLSAMPLERPARAMETERIPROC>(wglGetProcAddress("glSamplerParameteri"));

        #pragma endregion
        #pragma region Framebuffers

        glCreateFramebuffers = reinterpret_cast<PFNGLCREATEFRAMEBUFFERSPROC>(wglGetProcAddress("glCreateFramebuffers"));
        glDeleteFramebuffers = reinterpret_cast<PFNGLDELETEFRAMEBUFFERSPROC>(wglGetProcAddress("glDeleteFramebuffers"));

        #pragma endregion
    }
}