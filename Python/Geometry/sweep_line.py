import random
from PIL import Image, ImageDraw








if __name__ == "__main__":
    range_value = 500
    n = 10
    # todo : how to generate specific range number of intersections 
    startpoint_x = [random.randrange(range_value) for i in range(n)]
    startpoint_y = [random.randrange(range_value) for i in range(n)]
    endpoint_x = [random.randrange(range_value) for i in range(n)]
    endpoint_y = [random.randrange(range_value) for i in range(n)] 

    startpoints =[]
    endpoints =[]

    for i in range(n):
        startpoints.append((startpoint_x[i],startpoint_y[i]))
        endpoints.append((endpoint_x[i],endpoint_y[i]))
    im = Image.new('RGB', (500, 300), (128, 128, 128))
    draw = ImageDraw.Draw(im)
    for i in range(n):
        draw.line((startpoints[i],endpoints[i]),fill=(255,255,0))
    #draw.line(((30, 200), (130, 100), (80, 50)), fill=(255, 255, 0))
    #draw.line(((80, 200), (180, 100), (130, 50)), fill=(255, 255, 0), width=10)
    im.show()
