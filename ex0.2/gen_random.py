import time
import numpy as np

N = 10^9  # 1 000 000 000

# a) Generate random number in one shot
start = time.time()
arr = np.random.rand(N)
end = time.time()
print(f"Single batch generation: {end - start:.3e} sec")

# b) Generate in chunks
chunks = 1000  # Split into 1000 parts
chunk_size = N // chunks

start = time.time()
for _ in range(chunks):
    np.random.rand(chunk_size)  # A smaller batch
end = time.time()
print(f"Chunked generation: {end - start:.3e} sec")