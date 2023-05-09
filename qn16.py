import string
from collections import Counter

def decrypt(ciphertext, key):
    plaintext = ""
    for char in ciphertext:
        if char.isalpha():
            if char.isupper():
                decrypted_char = key[char.lower()].upper()
            else:
                decrypted_char = key[char]
            plaintext += decrypted_char
        else:
            plaintext += char
    return plaintext

def letter_frequency_attack(ciphertext, num_results):
    frequencies = Counter(ciphertext.lower())
    sorted_frequencies = sorted(frequencies.items(), key=lambda x: x[1], reverse=True)
    most_common_letters = [char for char, _ in sorted_frequencies if char.isalpha()]

    results = []
    for perm in permutations(string.ascii_lowercase):
        key = {ciphertext[i]: perm[i] for i in range(len(perm))}
        possible_plaintext = decrypt(ciphertext, key)
        result = ""
        for char in possible_plaintext:
            if char.lower() in most_common_letters:
                result += char
            else:
                result += "."
        results.append(result)

    return results[:num_results]

def main():
    ciphertext = "Lb tl'ua lzw kltw lba amvlsbopun avvs."
    num_results = 10

    results = letter_frequency_attack(ciphertext, num_results)

    print(f"Top {num_results} possible plaintexts:")
    for i, result in enumerate(results, 1):
        print(f"{i}. {result}")

if __name__ == "__main__":
    main()
