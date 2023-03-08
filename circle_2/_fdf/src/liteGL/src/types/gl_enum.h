/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_enum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:52:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 14:30:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_ENUM_H
# define GL_ENUM_H

enum
{
	SMOOTH,
	FLAT,
	NOPERSPECTIVE
};

enum
{
	GL_NO_ERROR = 0,
	GL_INVALID_ENUM,
	GL_INVALID_VALUE,
	GL_INVALID_OPERATION,
	GL_INVALID_FRAMEBUFFER_OPERATION,
	GL_OUT_OF_MEMORY,
	GL_ARRAY_BUFFER,
	GL_COPY_READ_BUFFER,
	GL_COPY_WRITE_BUFFER,
	GL_ELEMENT_ARRAY_BUFFER,
	GL_PIXEL_PACK_BUFFER,
	GL_PIXEL_UNPACK_BUFFER,
	GL_TEXTURE_BUFFER,
	GL_TRANSFORM_FEEDBACK_BUFFER,
	GL_UNIFORM_BUFFER,
	GL_NUM_BUFFER_TYPES,
	GL_FRAMEBUFFER,
	GL_DRAW_FRAMEBUFFER,
	GL_READ_FRAMEBUFFER,
	GL_COLOR_ATTACHMENT0,
	GL_COLOR_ATTACHMENT1,
	GL_COLOR_ATTACHMENT2,
	GL_COLOR_ATTACHMENT3,
	GL_COLOR_ATTACHMENT4,
	GL_COLOR_ATTACHMENT5,
	GL_COLOR_ATTACHMENT6,
	GL_COLOR_ATTACHMENT7,
	GL_DEPTH_ATTACHMENT,
	GL_STENCIL_ATTACHMENT,
	GL_DEPTH_STENCIL_ATTACHMENT,
	GL_RENDERBUFFER,
	GL_STREAM_DRAW,
	GL_STREAM_READ,
	GL_STREAM_COPY,
	GL_STATIC_DRAW,
	GL_STATIC_READ,
	GL_STATIC_COPY,
	GL_DYNAMIC_DRAW,
	GL_DYNAMIC_READ,
	GL_DYNAMIC_COPY,
	GL_READ_ONLY,
	GL_WRITE_ONLY,
	GL_READ_WRITE,
	GL_POINT,
	GL_LINE,
	GL_FILL,
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_LINE_STRIP_ADJACENCY,
	GL_LINES_ADJACENCY,
	GL_TRIANGLES_ADJACENCY,
	GL_TRIANGLE_STRIP_ADJACENCY,
	GL_LESS,
	GL_LEQUAL,
	GL_GREATER,
	GL_GEQUAL,
	GL_EQUAL,
	GL_NOTEQUAL,
	GL_ALWAYS,
	GL_NEVER,
	GL_ZERO,
	GL_ONE,
	GL_SRC_COLOR,
	GL_ONE_MINUS_SRC_COLOR,
	GL_DST_COLOR,
	GL_ONE_MINUS_DST_COLOR,
	GL_SRC_ALPHA,
	GL_ONE_MINUS_SRC_ALPHA,
	GL_DST_ALPHA,
	GL_ONE_MINUS_DST_ALPHA,
	GL_CONSTANT_COLOR,
	GL_ONE_MINUS_CONSTANT_COLOR,
	GL_CONSTANT_ALPHA,
	GL_ONE_MINUS_CONSTANT_ALPHA,
	GL_SRC_ALPHA_SATURATE,
	NUM_BLEND_FUNCS,
	GL_SRC1_COLOR,
	GL_ONE_MINUS_SRC1_COLOR,
	GL_SRC1_ALPHA,
	GL_ONE_MINUS_SRC1_ALPHA,
	GL_FUNC_ADD,
	GL_FUNC_SUBTRACT,
	GL_FUNC_REVERSE_SUBTRACT,
	GL_MIN,
	GL_MAX,
	NUM_BLEND_EQUATIONS,
	GL_TEXTURE_UNBOUND,
	GL_TEXTURE_1D,
	GL_TEXTURE_2D,
	GL_TEXTURE_3D,
	GL_TEXTURE_1D_ARRAY,
	GL_TEXTURE_2D_ARRAY,
	GL_TEXTURE_RECTANGLE,
	GL_TEXTURE_CUBE_MAP,
	GL_NUM_TEXTURE_TYPES,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
	GL_TEXTURE_BASE_LEVEL,
	GL_TEXTURE_BORDER_COLOR,
	GL_TEXTURE_COMPARE_FUNC,
	GL_TEXTURE_COMPARE_MODE,
	GL_TEXTURE_LOD_BIAS,
	GL_TEXTURE_MIN_FILTER,
	GL_TEXTURE_MAG_FILTER,
	GL_TEXTURE_MIN_LOD,
	GL_TEXTURE_MAX_LOD,
	GL_TEXTURE_MAX_LEVEL,
	GL_TEXTURE_SWIZZLE_R,
	GL_TEXTURE_SWIZZLE_G,
	GL_TEXTURE_SWIZZLE_B,
	GL_TEXTURE_SWIZZLE_A,
	GL_TEXTURE_SWIZZLE_RGBA,
	GL_TEXTURE_WRAP_S,
	GL_TEXTURE_WRAP_T,
	GL_TEXTURE_WRAP_R,
	GL_REPEAT,
	GL_CLAMP_TO_EDGE,
	GL_CLAMP_TO_BORDER,
	GL_MIRRORED_REPEAT,
	GL_NEAREST,
	GL_LINEAR,
	GL_NEAREST_MIPMAP_NEAREST,
	GL_NEAREST_MIPMAP_LINEAR,
	GL_LINEAR_MIPMAP_NEAREST,
	GL_LINEAR_MIPMAP_LINEAR,
	GL_RED,
	GL_RG,
	GL_RGB,
	GL_BGR,
	GL_RGBA,
	GL_BGRA,
	GL_COMPRESSED_RED,
	GL_COMPRESSED_RG,
	GL_COMPRESSED_RGB,
	GL_COMPRESSED_RGBA,
	GL_DEPTH_COMPONENT16,
	GL_DEPTH_COMPONENT24,
	GL_DEPTH_COMPONENT32,
	GL_DEPTH_COMPONENT32F,
	GL_DEPTH24_STENCIL8,
	GL_DEPTH32F_STENCIL8,
	GL_STENCIL_INDEX1,
	GL_STENCIL_INDEX4,
	GL_STENCIL_INDEX8,
	GL_STENCIL_INDEX16,
	GL_UNPACK_ALIGNMENT,
	GL_PACK_ALIGNMENT,
	GL_TEXTURE0,
	GL_TEXTURE1,
	GL_TEXTURE2,
	GL_TEXTURE3,
	GL_TEXTURE4,
	GL_TEXTURE5,
	GL_TEXTURE6,
	GL_TEXTURE7,
	GL_CULL_FACE,
	GL_DEPTH_TEST,
	GL_DEPTH_CLAMP,
	GL_LINE_SMOOTH,
	GL_BLEND,
	GL_COLOR_LOGIC_OP,
	GL_POLYGON_OFFSET_FILL,
	GL_SCISSOR_TEST,
	GL_STENCIL_TEST,
	GL_FIRST_VERTEX_CONVENTION,
	GL_LAST_VERTEX_CONVENTION,
	GL_POINT_SPRITE_COORD_ORIGIN,
	GL_UPPER_LEFT,
	GL_LOWER_LEFT,
	GL_FRONT,
	GL_BACK,
	GL_FRONT_AND_BACK,
	GL_CCW,
	GL_CW,
	GL_CLEAR,
	GL_SET,
	GL_COPY,
	GL_COPY_INVERTED,
	GL_NOOP,
	GL_AND,
	GL_NAND,
	GL_OR,
	GL_NOR,
	GL_XOR,
	GL_EQUIV,
	GL_AND_REVERSE,
	GL_AND_INVERTED,
	GL_OR_REVERSE,
	GL_OR_INVERTED,
	GL_INVERT,
	GL_KEEP,
	GL_REPLACE,
	GL_INCR,
	GL_INCR_WRAP,
	GL_DECR,
	GL_DECR_WRAP,
	GL_UNSIGNED_BYTE,
	GL_BYTE,
	GL_BITMAP,
	GL_UNSIGNED_SHORT,
	GL_SHORT,
	GL_UNSIGNED_INT,
	GL_INT,
	GL_FLOAT,
	GL_VENDOR,
	GL_RENDERER,
	GL_VERSION,
	GL_SHADING_LANGUAGE_VERSION,
	GL_POLYGON_OFFSET_FACTOR,
	GL_POLYGON_OFFSET_UNITS,
	GL_POINT_SIZE,
	GL_DEPTH_CLEAR_VALUE,
	GL_DEPTH_RANGE,
	GL_STENCIL_WRITE_MASK,
	GL_STENCIL_REF,
	GL_STENCIL_VALUE_MASK,
	GL_STENCIL_FUNC,
	GL_STENCIL_FAIL,
	GL_STENCIL_PASS_DEPTH_FAIL,
	GL_STENCIL_PASS_DEPTH_PASS,
	GL_STENCIL_BACK_WRITE_MASK,
	GL_STENCIL_BACK_REF,
	GL_STENCIL_BACK_VALUE_MASK,
	GL_STENCIL_BACK_FUNC,
	GL_STENCIL_BACK_FAIL,
	GL_STENCIL_BACK_PASS_DEPTH_FAIL,
	GL_STENCIL_BACK_PASS_DEPTH_PASS,
	GL_LOGIC_OP_MODE,
	GL_BLEND_SRC_RGB,
	GL_BLEND_SRC_ALPHA,
	GL_BLEND_DST_RGB,
	GL_BLEND_DST_ALPHA,
	GL_BLEND_EQUATION_RGB,
	GL_BLEND_EQUATION_ALPHA,
	GL_CULL_FACE_MODE,
	GL_FRONT_FACE,
	GL_DEPTH_FUNC,
	GL_PROVOKING_VERTEX,
	GL_POLYGON_MODE,
	GL_MAJOR_VERSION,
	GL_MINOR_VERSION,
	GL_TEXTURE_BINDING_1D,
	GL_TEXTURE_BINDING_1D_ARRAY,
	GL_TEXTURE_BINDING_2D,
	GL_TEXTURE_BINDING_2D_ARRAY,
	GL_TEXTURE_BINDING_2D_MULTISAMPLE,
	GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY,
	GL_TEXTURE_BINDING_3D,
	GL_TEXTURE_BINDING_BUFFER,
	GL_TEXTURE_BINDING_CUBE_MAP,
	GL_TEXTURE_BINDING_RECTANGLE,
	GL_COMPUTE_SHADER,
	GL_VERTEX_SHADER,
	GL_TESS_CONTROL_SHADER,
	GL_TESS_EVALUATION_SHADER,
	GL_GEOMETRY_SHADER,
	GL_FRAGMENT_SHADER,
	GL_INFO_LOG_LENGTH,
	GL_COMPILE_STATUS,
	GL_LINK_STATUS,
	GL_COLOR_BUFFER_BIT = 1 << 10,
	GL_DEPTH_BUFFER_BIT = 1 << 11,
	GL_STENCIL_BUFFER_BIT = 1 << 12
};

#endif