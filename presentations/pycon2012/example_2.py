import lzma

data = b"Insert Data Here"

with lzma.LZMAFile("file.xz", "w") as f:
   f.write(data)

with lzma.LZMAFile("file.xz") as f:
   file_content = f.read()

print(file_content)
