#include <iostream>
#include <cmath>
#include <string>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include "SUVAT_Proj.h"

using namespace std;

int main()
{

    //Upto ImGui context i am lost, will spend some time learning 

    // Initialize GLFW
    if (!glfwInit())
        return -1;

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(1280, 800, "SUVAT Calculator", NULL, NULL);
    if (window == NULL)
        return -1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();   
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();   //Getting input and output, simple to understand and use (ImGuiIO is a structure that holds the input and output data for ImGui)

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Application state
    static int selectedVar = 0;
    static char inputS[64] = "";
    static char inputU[64] = "";
    static char inputV[64] = "";
    static char inputA[64] = "";
    static char inputT[64] = "";
    static double result = 0.0;
    static bool calculated = false;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(io.DisplaySize);
        ImGui::Begin("SUVAT Calculator", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        ImGui::Text("Welcome to the SUVAT Calculator!");
        ImGui::Separator();

        ImGui::Text("Select the variable to calculate:");
        const char* variables[] = { "S (Displacement)", "U (Initial Velocity)", "V (Final Velocity)", "A (Acceleration)", "T (Time)" };
        ImGui::Combo("Calculate", &selectedVar, variables, IM_ARRAYSIZE(variables));

        ImGui::Separator();
        ImGui::Text("Enter known values (use 'x' or 'X' for unknown):");

        if (selectedVar != 0) ImGui::InputText("S", inputS, IM_ARRAYSIZE(inputS));
        if (selectedVar != 1) ImGui::InputText("U", inputU, IM_ARRAYSIZE(inputU));
        if (selectedVar != 2) ImGui::InputText("V", inputV, IM_ARRAYSIZE(inputV));
        if (selectedVar != 3) ImGui::InputText("A", inputA, IM_ARRAYSIZE(inputA));
        if (selectedVar != 4) ImGui::InputText("T", inputT, IM_ARRAYSIZE(inputT));

        ImGui::Separator();

        if (ImGui::Button("Calculate", ImVec2(120, 40)))
        {
            try {
                switch (selectedVar)
                {
                case 0: // Calculate S
                    result = calculateS(string(inputU), string(inputV), string(inputA), string(inputT));
                    break;
                case 1: // Calculate U
                    result = calculateU(string(inputS), string(inputV), string(inputA), string(inputT));
                    break;
                case 2: // Calculate V
                    result = calculateV(string(inputS), string(inputU), string(inputA), string(inputT));
                    break;
                case 3: // Calculate A
                    result = calculateA(string(inputS), string(inputU), string(inputV), string(inputT));
                    break;
                case 4: // Calculate T
                    result = calculateT(string(inputS), string(inputU), string(inputV), string(inputA));
                    break;
                }
                calculated = true;
            }
            catch (...) {
                result = 0.0;
                calculated = false;
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("Clear", ImVec2(120, 40)))
        {
            memset(inputS, 0, sizeof(inputS));
            memset(inputU, 0, sizeof(inputU));
            memset(inputV, 0, sizeof(inputV));
            memset(inputA, 0, sizeof(inputA));
            memset(inputT, 0, sizeof(inputT));
            result = 0.0;
            calculated = false;
        }

        if (calculated)
        {
            ImGui::Separator();
            ImGui::Text("Result: %.4f", result);
        }

        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

