from Crypto.Cipher import DES3
from Crypto.Util.Padding import pad

# key must be 16 or 24 bytes long
key = b'SuperSecretKey123'
iv = b'InitializationVe'

# plaintext must be a multiple of 8 bytes long
plaintext = b'Hello world!'

cipher = DES3.new(key, DES3.MODE_CBC, iv)
ciphertext = cipher.encrypt(pad(plaintext, 8))

print(ciphertext.hex())
