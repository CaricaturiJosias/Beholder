
#include <iostream>
#include <fstream>
#include <string>

#include "SchemaHelpers/AnalogData.hh"

// Apache Avro related imports
#include <avro/ValidSchema.hh>
#include <avro/Compiler.hh>
#include <avro/Decoder.hh>
#include <avro/Encoder.hh>
#include <avro/DataFile.hh>
#include <avro/Stream.hh>

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Made by Amit Kulkarni in https://medium.com/@amit.kulkarni/encrypting-decrypting-a-file-using-openssl-evp-b26e0e4d28d4
typedef struct _cipher_params_t{
    unsigned char *key;
    unsigned char *iv;
    unsigned int encrypt;
    const EVP_CIPHER *cipher_type;
}cipher_params_t;

/* 32 byte key (256 bit key) */
#define AES_256_KEY_SIZE 32

bool encrypt(std::string file) {
    FILE *f_input, *f_enc, *f_dec;

    // 
    cipher_params_t *params = (cipher_params_t *)malloc(sizeof(cipher_params_t));
    if (!params) {
        /* Unable to allocate memory on heap*/
        std::cout <<  "ERROR: malloc error: " << strerror(errno) << std::endl;
        return false;
    }

    /* Key to use for encrpytion and decryption */
    unsigned char key[AES_256_KEY_SIZE];

    /* Initialization Vector */
    unsigned char iv[AES_BLOCK_SIZE];

    /* Generate cryptographically strong pseudo-random bytes for key and IV */
    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        /* OpenSSL reports a failure, act accordingly */
        fprintf(stderr, "ERROR: RAND_bytes error: %s\n", strerror(errno));
        return false;
    }

    params->key = key;
    params->iv = iv;

    // we want to encrypt
    params->encrypt = 1;

    /* Set the cipher type you want for encryption-decryption */
    params->cipher_type = EVP_aes_256_cbc();

    /* Open the input file for reading in binary ("rb" mode) */
    f_input = fopen(file.c_str(), "rb");
    if (!f_input) {
        /* Unable to open file for reading */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return false;
    }

    /* Open and truncate file to zero length or create ciphertext file for writing */
    f_enc = fopen("encrypted_file", "wb");
    if (!f_enc) {
        /* Unable to open file for writing */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return false;
    }

    /* Encrypt the given file */
    // EVP_CipherUpdate
    /* Encryption done, close the file descriptors */
    // fclose(f_input);
    fclose(f_enc);

    /* Decrypt the file */
    /* Indicate that we want to decrypt */
    params->encrypt = 0;

    /* Open the encrypted file for reading in binary ("rb" mode) */
    f_input = fopen("encrypted_file", "rb");
    if (!f_input) {
        /* Unable to open file for reading */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return false;
    }

    /* Open and truncate file to zero length or create decrypted file for writing */
    f_dec = fopen("decrypted_file", "wb");
    if (!f_dec) {
        /* Unable to open file for writing */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return false;
    }

    /* Decrypt the given file */
    // file_encrypt_decrypt(params, f_input, f_dec);

    /* Close the open file descriptors */
    fclose(f_input);
    fclose(f_dec);

    /* Free the memory allocated to our structure */
    free(params);

    return false;
}

int main () {
    std::string outputFile = "test.tmp";
    std::string finalFile = "/home/cezario/beholder/Adata_0.bin";
    std::ifstream ifs("AnalogData.json");

    avro::ValidSchema schemaResult;
    avro::compileJsonSchema(ifs, schemaResult);
    // // GENERATION OF INSTANCES
    
    // c::Analog analog;
    // avro::DataFileWriter<c::Analog>
    // writerInstance(
    //     outputFile.c_str(),
    //     schemaResult,
    //     16 * 1024,
    //     avro::DEFLATE_CODEC);

    // for (int i = 1; i < 10; i++) {
    //     analog.value = i;
    //     analog.quality = i;
    //     analog.id = i;
    //     analog.timestamp = std::to_string(i);
    //     // writerInstance.write(analog);
    // }
    // // writerInstance.close();

    // // Now transport the content to another file
    // std::ifstream temp(outputFile);
    // // std::ios::app allow us to actually append
    // std::ofstream final("test.bin", std::ios::app);
    // if (!temp.is_open() || !final.is_open()) {
    //     std::cout << "???" << std::endl;
    // }
    // final << temp.rdbuf();
    // final << "\n";
    // temp.close();
    // final.close();

    avro::DataFileReader<c::Analog> readerInstance(finalFile.c_str(), schemaResult);

    c::Analog analog2;
    bool teste = false;
    while(readerInstance.read(analog2)) {
        // std::cout << "read? " << ((teste) ? "Yes" : "No") << std::endl;
        std::cout << "id: " << analog2.id
                << ", quality: " << analog2.quality 
                << ", timestamp: " << analog2.timestamp
                << ", value: " << analog2.value
                << std::endl;
    }
    readerInstance.close();
    // encrypt(outputFile);
}