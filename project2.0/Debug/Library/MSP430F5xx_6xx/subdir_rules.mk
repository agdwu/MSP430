################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Library/MSP430F5xx_6xx/%.obj: ../Library/MSP430F5xx_6xx/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/TI/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/Users/1/Desktop/2/Software" --include_path="D:/TI/ccs1230/ccs/ccs_base/msp430/include" --include_path="C:/Users/1/Desktop/2/Hardware" --include_path="C:/Users/1/Desktop/2/Bsp" --include_path="C:/Users/1/Desktop/2/Library/MSP430F5xx_6xx" --include_path="C:/Users/1/Desktop/2" --include_path="D:/TI/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --include_path="C:/Users/1/Desktop/2/System" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="Library/MSP430F5xx_6xx/$(basename $(<F)).d_raw" --obj_directory="Library/MSP430F5xx_6xx" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


