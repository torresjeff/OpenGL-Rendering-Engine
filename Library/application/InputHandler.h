#pragma once

#include <GLFW/glfw3.h>

/*
 * Default key callback. Can be changed with Application::SetKeyCallback
 */
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
