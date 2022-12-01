#include <cstdint>
#include <cstdio>


void Print_Byte_Bin(uint8_t val){
    uint8_t bin_digits[8];
    for(uint8_t i=0;i<8;i++){
        bin_digits[i]= (uint8_t)((val & 0x01));
        val>>=1;
    }
    printf("0b");
    for(uint8_t i=8;i>0;i--){
        uint8_t index=(uint8_t)(i-1);
        printf("%d",bin_digits[index]);
    }
}

int main(){
    uint8_t test;
    test = 255/4;
    //printf("%u", (unsigned int)test);
    Print_Byte_Bin(test);

}