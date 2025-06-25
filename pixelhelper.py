from PIL import Image
import numpy as np

path = 'image.png'
image = Image.open(path)
image = np.asarray(image)