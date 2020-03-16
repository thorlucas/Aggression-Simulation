#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace BromineEngine {
	using Vec2 = glm::vec2;
	using Vec3 = glm::vec3;
	using Vec4 = glm::vec4;

	using Vec2f = glm::vec2;
	using Vec3f = glm::vec3;
	using Vec4f = glm::vec4;

	using Vec2d = glm::dvec2;
	using Vec3d = glm::dvec3;
	using Vec4d = glm::dvec4;

	using Vec2b = glm::bvec2;
	using Vec3b = glm::bvec3;
	using Vec4b = glm::bvec4;

	using Vec2i = glm::ivec2;
	using Vec3i = glm::ivec3;
	using Vec4i = glm::ivec4;

	using Vec2u = glm::uvec2;
	using Vec3u = glm::uvec3;
	using Vec4u = glm::uvec4;

	using  Mat2f 	= glm::mat2;
	using  Mat2x2f 	= glm::mat2x2;
	using  Mat2x3f 	= glm::mat2x3;
	using  Mat2x4f 	= glm::mat2x4;

	using  Mat3x2f 	= glm::mat3x2;
	using  Mat3f 	= glm::mat3;
	using  Mat3x3f 	= glm::mat3x3;
	using  Mat3x4f 	= glm::mat3x4;

	using  Mat4x2f 	= glm::mat4x2;
	using  Mat4x3f 	= glm::mat4x3;
	using  Mat4f 	= glm::mat4;
	using  Mat4x4f 	= glm::mat4x4;

	template <glm::length_t C, glm::length_t R, typename T> 
	using Mat = glm::mat<C, R, T>; // TODO: defaultp isn't anything?

	template <glm::length_t R, typename T>
	using Vec = glm::vec<R, T>;

	template <typename M>
	inline std::string matrixToString(M& mat) {
		return glm::to_string(mat);
	}
}