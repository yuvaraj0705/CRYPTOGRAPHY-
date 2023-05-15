from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import random

def encrypt_ecb(key, plaintext):
    cipher = AES.new(key, AES.MODE_ECB)
    ciphertext = cipher.encrypt(pad(plaintext, AES.block_size))
    return ciphertext

def decrypt_ecb(key, ciphertext):
    cipher = AES.new(key, AES.MODE_ECB)
    plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
    return plaintext

def encrypt_cbc(key, iv, plaintext):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    ciphertext = cipher.encrypt(pad(plaintext, AES.block_size))
    return ciphertext

def decrypt_cbc(key, iv, ciphertext):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
    return plaintext

# ECB Mode
def ecb_mode_example():
    key = b'Sixteen byte key'
    plaintext = b'This is the plaintext'

    # Encryption
    ciphertext = encrypt_ecb(key, plaintext)
    print("Ciphertext (ECB):", ciphertext)

    # Introduce an error in the ciphertext (at the block level)
    corrupted_ciphertext = bytearray(ciphertext)
    corrupted_ciphertext[16] = 0

    # Decryption
    try:
        decrypted_plaintext = decrypt_ecb(key, corrupted_ciphertext)
        print("Decrypted Plaintext (ECB):", decrypted_plaintext)
    except ValueError as e:
        print("Decryption Error (ECB):", str(e))

# CBC Mode
def cbc_mode_example():
    key = b'Sixteen byte key'
    iv = b'This is an IV456'

    plaintext = b'This is the plaintext'

    # Encryption
    ciphertext = encrypt_cbc(key, iv, plaintext)
    print("Ciphertext (CBC):", ciphertext)

    # Introduce an error in the ciphertext (at the block level)
    corrupted_ciphertext = bytearray(ciphertext)
    corrupted_ciphertext[16] = 0

    # Decryption
    try:
        decrypted_plaintext = decrypt_cbc(key, iv, corrupted_ciphertext)
        print("Decrypted Plaintext (CBC):", decrypted_plaintext)
    except ValueError as e:
        print("Decryption Error (CBC):", str(e))

# Run the examples
ecb_mode_example()
print()
cbc_mode_example()
