# STEP 1:
write a pytorch model for CIFAR 10
This model is simple, uses two convolutional layers and four fully connected linear layers
The model saves the torchscripted module as model.pt

# STEP 2:
convert the code from .pt format using c++ code
write C++ code that reads and test the values in the model by loading it
create a CMakesLists file for some important compiling informations
download libtorch from pytorch website (use the correct versions for the correct OS)
run the lines from the C++ conversion page in pytorch website
NOTE: I have not added build and data folders here in this repo and they should built accordingly

# STEP 3:
Modify the CMakesLists file to make the output more verbose and display more details.
