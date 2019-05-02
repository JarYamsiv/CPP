#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "headers/GL.h"

#include <iostream>


void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window, float *vertexArray);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


namespace GL
{
    int LinkShaders(const char* filename,int *status=NULL)
    {
        //read the file and differentiate vertex and fragment programm

        int shaderProgram;
        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
            << infoLog << std::endl;
            if(status!=NULL)*status = -1;
        }
        // fragment shader
        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
            << infoLog << std::endl;
            if(status!=NULL)*status = -1;
        }
        // link shaders
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
            << infoLog << std::endl;
            if(status!=NULL)*status = -1;

        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return shaderProgram;
    }

    int LinkShaders(const char* v_filename,const char* f_filename,int *status=NULL)
    {
        //read the file and differentiate vertex and fragment programm
        FILE *f = fopen(v_filename, "rb");
        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        fseek(f, 0, SEEK_SET);

        char *vs_prog = (char *)malloc(fsize + 1);
        fread(vs_prog, fsize, 1, f);
        fclose(f);

        vs_prog[fsize] = 0;

        f = fopen(f_filename, "rb");
        fseek(f, 0, SEEK_END);
        fsize = ftell(f);
        fseek(f, 0, SEEK_SET);

        char *fs_prog = (char *)malloc(fsize + 1);
        fread(fs_prog, fsize, 1, f);
        fclose(f);

        fs_prog[fsize] = 0;


        int shaderProgram;
        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vs_prog, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
            << infoLog << std::endl;
            if(status!=NULL)*status = -1;
        }
        // fragment shader
        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fs_prog, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
            << infoLog << std::endl;
            if(status!=NULL)*status = -1;
        }
        // link shaders
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
            << infoLog << std::endl;
            if(status!=NULL)*status = -1;

        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        free(vs_prog);
        free(fs_prog);
        return shaderProgram;
    }

    GLFWwindow* Init(unsigned int SCR_WIDTH,unsigned int SCR_HEIGHT)
    {
        // glfw: initialize and configure
    // ------------------------------
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /*
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif
    */

    // glfw window creation
    // --------------------
        GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            exit(-1);
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
        glewExperimental = GL_TRUE;
        glewInit();
        return window;
    }
}





int main()
{
    int status;

    //Init gl
    GLFWwindow *window = GL::Init(SCR_WIDTH,SCR_HEIGHT);

    // build and compile our shader program
    
    int shaderProgram = GL::LinkShaders("shaders/vert.vs","shaders/frag.fs",&status);
    
    
    if(status==-1){
        fprintf(stderr, "compilation of shaders failed exiting\n" );
        exit(-1);
    }
    

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
       0.25f,  0.25f, 0.0f,
       0.25f, -0.25f, 0.0f,
       -0.25f, -0.25f, 0.0f,
       -0.25f, -0.25f, 0.0f,
       -0.25f,  0.25f, 0.0f,
       0.25f,  0.25f, 0.0f
   };
   unsigned int VBO, VAO;
   glGenVertexArrays(1, &VAO);
   glGenBuffers(1, &VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).


        //this part is important
   glBindVertexArray(VAO);

   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
   glEnableVertexAttribArray(0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glBindVertexArray(0);
        //the binding ends here



   int nbFrames;
   double lastTime, currentTime;
   glBindVertexArray(VAO);

   while (!glfwWindowShouldClose(window))
   {
            // input
            // -----
    processInput(window, vertices);

    currentTime = glfwGetTime();
    nbFrames++;
    if (currentTime - lastTime >= 1.0)
    { 
        std::cout << 1000.0 / double(nbFrames) << " ms/frame " << nbFrames << " fps" << std::endl;
        nbFrames = 0;
        lastTime += 1.0;
    }

            // render
            // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

            //binding different VBOs are faster than multiple VAOs
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);


    glUseProgram(shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 6);


    glfwSwapBuffers(window);
    glfwPollEvents();
}

        // optional: de-allocate all resources once they've outlived their purpose:
        // ------------------------------------------------------------------------
glDeleteVertexArrays(1, &VAO);
glDeleteBuffers(1, &VBO);

        // glfw: terminate, clearing all previously allocated GLFW resources.
        // ------------------------------------------------------------------
glfwTerminate();
return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window, float *vertex)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        for (int i = 0; i < 4; i++)
            vertex[0 + 3 * i] += 0.0025;
    }

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        for (int i = 0; i < 4; i++)
            vertex[0 + 3 * i] -= 0.0025;
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
