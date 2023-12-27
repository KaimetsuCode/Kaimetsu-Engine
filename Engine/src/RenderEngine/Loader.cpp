#include "Loader.hpp"
#include <iostream>
#include <iterator>

Loader::Loader(/* args */)
{
}



void Loader::StoreDataInAttributeList(int attribNum, int coordinateSize, std::vector<float> data) {
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    vbos.push_back(vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(attribNum, coordinateSize, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::BindIndiciesBuffer(std::vector<unsigned int> indicies) {
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    vbos.push_back(EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(float), &indicies.front(), GL_STATIC_DRAW);
}

unsigned int Loader::LoadTexture(std::string fileName) {
    std::string file = "./Assets/Images/" + fileName;
    SDL_Surface* image = IMG_Load(file.c_str());
    unsigned int texture_id;
	if (image == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Image not found", file.c_str(), NULL);
	}
	glGenTextures(1, &texture_id); // Generates Texture ID
	glBindTexture(GL_TEXTURE_2D, texture_id); // Binds Texture ID to OpenGL Pipeline

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Settings for Texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	int format;
	if (image->format->BytesPerPixel == 4) {
		if (image->format->Rmask == 0x000000ff)
			format = GL_RGBA;
		else
			format = GL_BGRA; // Adjust accordingly based on your system's endianness
	}
	else if (image->format->BytesPerPixel == 3) {
		if (image->format->Rmask == 0x000000ff)
			format = GL_RGB;
		else
			format = GL_BGR; // Adjust accordingly based on your system's endianness
	}
	else {
		// Handle unsupported format
		SDL_Log("Unsupported pixel format");
		SDL_FreeSurface(image);
	}

	std::cout << format << std::endl;

	glTexImage2D(GL_TEXTURE_2D, 0, format, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);
	glGenerateMipmap(GL_TEXTURE_2D);
	SDL_FreeSurface(image);
	glBindTexture(GL_TEXTURE_2D, 0);

    textures.push_back(texture_id);

    return texture_id;
}

unsigned int Loader::CreateVAO() {
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

RawModel* Loader::LoadToVAO(std::vector<float> positions, std::vector<float> textureCoords, std::vector<unsigned int> indices) {
    unsigned int vao = CreateVAO();
    vaos.push_back(vao);
    BindIndiciesBuffer(indices);
    StoreDataInAttributeList(0, 3, positions);
    StoreDataInAttributeList(1, 2, textureCoords);
    UnbindVAO();
    return new RawModel(vao, std::size(indices));
}

Loader::~Loader()
{
    for(auto& vao: vaos) {
        glDeleteVertexArrays(1, &vao);
    }

    for(auto& vbo: vbos) {
        glDeleteBuffers(1, &vbo);
    }

    for(auto& tex: textures) {
        glDeleteTextures(1, &tex);
    }
}
