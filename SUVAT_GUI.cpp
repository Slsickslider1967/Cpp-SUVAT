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
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE); // Remove window borders and title bar

    GLFWwindow* window = glfwCreateWindow(1280, 800, "SUVAT Calculator", NULL, NULL);
    if (window == NULL)
        return -1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();   
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();   //Getting input and output, simple to understand and use (ImGuiIO is a structure that holds the input and output data for ImGui)

    ImGui::StyleColorsDark();   //Setting style

    ImGui_ImplGlfw_InitForOpenGL(window, true); //Initializing ImGui for GLFW and OpenGL3
    ImGui_ImplOpenGL3_Init(glsl_version);   //Initializing ImGui for OpenGL3 with the specified GLSL version

    // Application state
    static int selectedVar = 0;
    static char inputS[64] = "";
    static char inputU[64] = "";
    static char inputV[64] = "";
    static char inputA[64] = "";
    static char inputT[64] = "";
    static double result = 0.0;
    static bool calculated = false;
    static bool duelMode = false;

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();   //User Input

        ImGui_ImplOpenGL3_NewFrame();   //Start new ImGui frame for OpenGL3
        ImGui_ImplGlfw_NewFrame();      //Start new ImGui frame for GLFW
        ImGui::NewFrame();          //Start new ImGui frame

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(io.DisplaySize);
        ImGui::Begin("SUVAT Calculator", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        ImGui::Text("Welcome to the SUVAT Calculator!");
        ImGui::Separator();

        ImGui::Checkbox("Duel Mode (Calculate two variables at once)", &duelMode);
        if (duelMode)        {
            ImGui::Text("Duel Mode is currently under development. Please check back later for updates.");
            ImGui::End();
            ImGui::Render();   //Render ImGui frame
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            glfwSwapBuffers(window);
            continue;
        }

        ImGui::Separator();
        ImGui::Text("Select the variable to calculate:");
        const char* variables[] = { "S (Displacement)", "U (Initial Velocity)", "V (Final Velocity)", "A (Acceleration)", "T (Time)" };
        ImGui::Combo("Calculate", &selectedVar, variables, IM_ARRAYSIZE(variables));

        ImGui::Separator();
        ImGui::Text("Enter known values (use 'x' or 'X' for unknown):");

        //Im_ArraySize is a macro that calculates the number of elements in an array, it is defined as #define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*(_ARR))))

        if (selectedVar != 0) ImGui::InputText("S##Input", inputS, IM_ARRAYSIZE(inputS));
        if (selectedVar != 1) ImGui::InputText("U##Input", inputU, IM_ARRAYSIZE(inputU));
        if (selectedVar != 2) ImGui::InputText("V##Input", inputV, IM_ARRAYSIZE(inputV));
        if (selectedVar != 3) ImGui::InputText("A##Input", inputA, IM_ARRAYSIZE(inputA));
        if (selectedVar != 4) ImGui::InputText("T##Input", inputT, IM_ARRAYSIZE(inputT));
        ImGui::Separator();

        if (ImGui::Button("Calculate##CalculateBtn", ImVec2(120, 40)))
        {
            try {
                switch (selectedVar)
                {
                case 0: // Calculate S`
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
        if (ImGui::Button("Clear##ClearBtn", ImVec2(120, 40)))
        {
            //Memset, Memeory reset, sets the first n bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char) and returns a pointer to the block of memory.
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
            ImGui::Text("Result: %.4f", result);
        }

        ImGui::End();

        ImGui::Render();   //Render ImGui frame
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    //Cleans up and exits
    ImGui_ImplOpenGL3_Shutdown();   //Shutdown ImGui for OpenGL3
    ImGui_ImplGlfw_Shutdown();  //Shutdown ImGui for OpenGL3 and GLFW
    ImGui::DestroyContext();    //Destroy ImGui context

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

