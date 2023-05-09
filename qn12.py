import numpy as np
def encrypt(message, key):
    # Convert the message to numeric values
    plaintext = [ord(char.lower()) - ord('a') for char in message if char.isalpha()]
    plaintext_len = len(plaintext)
    if plaintext_len % 2 != 0:
        plaintext.append(23)  # 'x'
    plaintext_matrix = np.array(plaintext).reshape(-1, 2)
    ciphertext_matrix = np.matmul(plaintext_matrix, key) % 26
    ciphertext = ciphertext_matrix.flatten().tolist()
    encrypted_message = ''.join(chr(val + ord('a')) for val in ciphertext)

    return encrypted_message

def decrypt(ciphertext, key):
    ciphertext = [ord(char.lower()) - ord('a') for char in ciphertext if char.isalpha()]
    ciphertext_matrix = np.array(ciphertext).reshape(-1, 2
    det = np.linalg.det(key)
    det_inv = pow(int(round(det)) % 26, -1, 26)
    key_inverse = (det_inv * np.linalg.inv(key) % 26).astype(int)
    plaintext_matrix = np.matmul(ciphertext_matrix, key_inverse) % 26
    plaintext = plaintext_matrix.flatten().tolist()
    decrypted_message = ''.join(chr(val + ord('a')) for val in plaintext)

    return decrypted_message
key = np.array([[9, 4], [5, 7]])
message = "meet me at the usual place at ten rather than eight o'clock"
encrypted_message = encrypt(message, key)
print("Encrypted message:", encrypted_message)

decrypted_message = decrypt(encrypted_message, key)
print("Decrypted message:", decrypted_message)
