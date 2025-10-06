#include <Arduino.h>
#include "aes.h"
// 128-bit AES key (16 bytes)
byte key[16] = {
  0x7a, 0x23, 0x15, 0xff,
  0xdd, 0xa3, 0xd4, 0x66,
  0xab, 0xfd, 0x22, 0x38,
  0x09, 0xcf, 0x47, 0x3a
};
// 16-byte block of plaintext
byte data[16] = {
  'P', '4', 'u', 'l', '2', 'a', 'S', 'U',
  'c', 'c', 'i', 'u', '6', '6', '3', '1'
};
// Utility function to print data in HEX
void printData(const char* label, byte* data, int len) {
  Serial.print(label);
  for (int i = 0; i < len; i++) {
    Serial.print(" ");
    if (data[i] < 16) Serial.print("0");
    Serial.print(data[i], HEX);
  }
  Serial.println();
}
//double avg = 0;
void setup() {
  Serial.begin(9600);
  //for (int i = 0; i < 10; i++) {
    delay(1000);
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);  // Initialize AES context with the key
    printData("Original: ", data, 16);
    unsigned long start = micros();
    AES_ECB_encrypt(&ctx, data);  // Perform encryption
    unsigned long end = micros();
    printData("Encrypted:", data, 16);
    Serial.print("Encryption Time: ");
    Serial.print(end - start);
    Serial.println(" microseconds");

    unsigned long start_decrypt = micros();
    AES_ECB_decrypt(&ctx, data);
    unsigned long end_decrypt = micros();
    printData("Decrypted:", data, 16);
    Serial.print("Decryption Time: ");
    Serial.print(end_decrypt - start_decrypt);
    Serial.println(" microseconds");

    //avg += end - start;
  //}
  //avg /= 10;
  //Serial.println(avg);

}
void loop() {
  // Not used
}