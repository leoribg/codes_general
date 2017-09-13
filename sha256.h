typedef struct {
   unsigned char data[64];
   uint32_t datalen;
   uint32_t bitlen[2];
   uint32_t state[8];
} SHA256_CTX;

uint32_t k[64];


void sha256_transform(SHA256_CTX *ctx, unsigned char data[]);
void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, unsigned char data[], uint32_t len);  
void sha256_final(SHA256_CTX *ctx, unsigned char hash[]); 
