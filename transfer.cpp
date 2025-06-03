#include <torch/script.h>
#include <iostream>
#include <memory>

int main(int argc, const char* argv[]){
    // if the user does not input two parameters while running raise an error
    if (argc != 2){
        std::cerr << "usage: example-app <path-to-exported-module>\n";
        return -1;
    }
    // declare a pytorch module instance and assign the value 
    torch::jit::script::Module module;
    try{
        module = torch::jit::load(argv[1]);
    }
    // raise an error if the module does not load
    catch (const c10::Error& e) {
    std::cerr << "error loading the model\n";
    return -1;
    }
    std::cout << "ok\n";

    // Create a vector of inputs.
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(torch::ones({1, 3, 32, 32}));

    // Execute the model and turn its output into a tensor.
    at::Tensor output = module.forward(inputs).toTensor();
    std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/5) << '\n';
}