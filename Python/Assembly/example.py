from peachpy import *
from peachpy.x86_64 import *

x = Argument(int32_t)
y = Argument(int32_t)

with Function("Add", (x, y), int32_t) as asm_function:
    reg_x = GeneralPurposeRegister32()
    reg_y = GeneralPurposeRegister32()

    LOAD.ARGUMENT(reg_x, x)
    LOAD.ARGUMENT(reg_y, y)

    ADD(reg_x, reg_y)

    RETURN(reg_x)

python_function = asm_function.finalize(abi.detect()).encode().load()

print(python_function(2, 2)) # -> prints "4"