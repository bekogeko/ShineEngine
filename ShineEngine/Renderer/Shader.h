#pragma once 
#include "../stdafx.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader
{
private:

	unsigned int m_RendererId;
	std::string m_FilePath;

	ShaderProgramSource ParseShader(const std::string& filePath);

	const std::string& LoadShaderFile(const std::string& filePath);
	void LoadShaderFile(const std::string& filePath, std::string& srcVar);

	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int GetUniformLocation(const std::string& name);
	void (*PreRenderEventFn)();
	

public:
	Shader(const std::string& filePath);
	Shader(const std::string& vertexFile, const std::string& fragmentFile);
	~Shader();

	void Bind()const;
	void Unbind() const;

	void SetUniform1f(const std::string& name, float v0);
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);
	void SetUniformMat4x4(const std::string& name, const float* ptr, int count=1, bool transpose=false);
	void SetPreRenderEvent(void (EventFn)())
	{
		PreRenderEventFn = EventFn;
	}
	void CallPreRender() {
		
		//ASSERT(PreRenderEventFn);
		PreRenderEventFn();
		
	}

};

