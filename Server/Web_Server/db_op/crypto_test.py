from Crypto import Random
from Crypto.PublicKey import RSA


# 伪随机数生成器
random_generator = Random.new().read
# rsa算法生成实例
rsa = RSA.generate(1024, random_generator)

# master的秘钥对的生成
private_pem = rsa.exportKey()

with open('master-private.pem', 'wb') as f:
    f.write(private_pem)

public_pem = rsa.publickey().exportKey()
with open('master-public.pem', 'wb') as f:
    f.write(public_pem)