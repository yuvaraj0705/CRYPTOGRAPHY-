import string
from collections import Counter

def decrypt(ciphertext, shift):
    plaintext = ""
    for char in ciphertext:
        if char.isalpha():
            if char.isupper():
                decrypted_char = chr((ord(char) - ord('A') - shift) % 26 + ord('A'))
            else:
                decrypted_char = chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
            plaintext += decrypted_char
        else:
            plaintext += char
    return plaintext

def letter_frequency_attack(ciphertext, num_results):
    frequencies = Counter(ciphertext.lower())
    sorted_frequencies = sorted(frequencies.items(), key=lambda x: x[1], reverse=True)
    most_common_letters = [char for char, _ in sorted_frequencies if char.isalpha()]

    results = []
    for shift in range(26):
        possible_plaintext = decrypt(ciphertext, shift)
        result = ""
        for char in possible_plaintext:
            if char.lower() in most_common_letters:
                result += char
            else:
                result += "."
        results.append(result)

    return results[:num_results]

def main():
    ciphertext = "Dydob dro zbybk"
    num_results = 10

    results = letter_frequency_attack(ciphertext, num_results)

    print(f"Top {num_results} possible plaintexts:")
    for i, result in enumerate(results, 1):
        print(f"{i}. {result}")

if __name__ == "__main__":
    main()
