def generate_sequence(n):
    # Initialize sequence
    sequence = [2, 4]
    
    # Initialize base
    base = 4

    while base <= 2**n:  # Updated condition
        # Find terms to add to base
        to_add = sequence[1::2]

        # Add each term to base and append to sequence
        for term in to_add:
            if term < base:
                sequence.append(base + term)
                
        # Double base
        base *= 2
        # Append base to sequence if it doesn't exceed 2^n
        if base <= 2**n:
            sequence.append(base)
        
    return sequence

# Rest of the code remains the same

def calculate_gap(n, sequence):
    # Find the largest term in the sequence less than 2^n
    largest_term = max(x for x in sequence if x < 2**n)
    
    # Calculate gap
    gap = 2**n - largest_term
    
    return gap

# Generate sequence for n up to 20
sequence = generate_sequence(40)

# Calculate and print gaps for n from 2 to 40
for n in range(2, 40):
    gap = calculate_gap(n, sequence)
    print(f"gap({n}) = {gap}")