def generate_round_keys(key):
    pc1 = [57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
           10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
           63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
           14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4]
    pc2 = [14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19,
           12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37,
           47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34,
           53, 46, 42, 50, 36, 29, 32]
    shift_schedule = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]
    permuted_key = [key[pc1[i] - 1] for i in range(56)]

    round_keys = []
    for round_num in range(16, 0, -1):
        shift_count = shift_schedule[16 - round_num]
        left_half = permuted_key[:28]
        right_half = permuted_key[28:]
        left_half = left_half[shift_count:] + left_half[:shift_count]
        right_half = right_half[shift_count:] + right_half[:shift_count]
        permuted_key = left_half + right_half
        round_key = [permuted_key[pc2[i] - 1] for i in range(48)]
        round_keys.append(round_key)

    return round_keys

def decrypt(message, round_keys):

    decrypted_message = ""
    return decrypted_message

def main():
   
    key = "011110110011110101010101011011100110011001111
