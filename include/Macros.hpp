//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MACROS_HPP
# define MACROS_HPP

#ifndef PI
# define PI (float) 3.14159265359
#endif

namespace gl_wrapper {

    #ifndef GENVERTEXARRAYS
    # define GENVERTEXARRAYS(n,id) if(GLEW_APPLE_vertex_array_object)glGenVertexArraysAPPLE(1,id);\
        else if (GLEW_ARB_vertex_array_object) glGenVertexArrays(n,id)
    #endif

    #ifndef BINDVERTEXARRAY
    # define BINDVERTEXARRAY(id) if(GLEW_APPLE_vertex_array_object)glBindVertexArrayAPPLE(id);\
        else if (GLEW_ARB_vertex_array_object) glBindVertexArray(id)
    #endif

}

#endif /* !MACROS_HPP */
