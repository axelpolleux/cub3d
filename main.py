import pygame
import math

def launch_as_ray(game, x):
	cameraX = 2 * x / float(game["swidth"]) - 1
	rayDirX = game["dirX"] + game["planeX"] * cameraX
	rayDirY = game["dirY"] + game["planeY"] * cameraX

	mapX = int(game["posX"])
	mapY = int(game["posY"])

	if (rayDirX == 0):
		deltaDistX = 1e30
	else:
		deltaDistX = abs(1 / rayDirX)
	if (rayDirY == 0):
		deltaDistY = 1e30
	else:
		deltaDistY = abs(1 / rayDirY)

	hit = 0

	if (rayDirX < 0):
		stepX = -1
		sideDistX = (game["posX"] - mapX) * deltaDistX
	else:
		stepX = 1
		sideDistX = (mapX + 1.0 - game["posX"]) * deltaDistX
	if (rayDirY < 0):
		stepY = -1
		sideDistY = (game["posY"] - mapY) * deltaDistY
	else:
		stepY = 1
		sideDistY = (mapY + 1.0 - game["posY"]) * deltaDistY

	while hit == 0:
		if (sideDistX < sideDistY):
			sideDistX += deltaDistX
			mapX += stepX
			side = 0
		else:
			sideDistY += deltaDistY
			mapY += stepY
			side = 1
		if (mapX < 0 or game["width"] < mapX or mapY < 0 or game["height"] < mapY):
			if (sideDistX < sideDistY):
				mapX -= stepX
			else:
				mapY -= stepY
			hit = 2
		elif (game["map"][mapX][mapY] > 0):
			hit = 1
	if side:
		perpWallDist = (sideDistY - deltaDistY)
	else:
		perpWallDist = (sideDistX - deltaDistX)

	h = game["sheight"]

	lineHeight = int(h / perpWallDist)

	drawStart = -lineHeight / 2 + h / 2
	if(drawStart < 0):
		drawStart = 0
	drawEnd = lineHeight / 2 + h / 2
	if(drawEnd >= h):
		drawEnd = h - 1

	# TODO find a way to use a differente color for each face
	# if (rayDirX < 0 and stepX > 0):
		# color = [255, 0, 0]
	# elif (rayDirX >= 0 and stepX < 0):
		# color = [0, 255, 0]
	# elif (rayDirY < 0 and stepY > 0):
		# color = [255, 255, 0]
	# elif (rayDirY >= 0 and stepY < 0):
		# color = [0, 0, 255]
	# else:
		# color = [0, 0, 0]

	if (side == 0):
		color = [200, 0, 0]
	else:
		color = [255, 0, 0]

	if (hit == 1):
		pygame.draw.line(game["screen"], color, (x, drawStart), (x, drawEnd))

def launch_ray(game):
	swidth = game["swidth"]
	for x in range (swidth):
		launch_as_ray(game, x)

def key_hook(game):
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			game["running"] = False

	keys = pygame.key.get_pressed()

	player = game
	map_table = game["map"]

	if keys[pygame.K_q]:
		oldDirX = game["dirX"]
		game["dirX"] = game["dirX"] * math.cos(-game["rotSpeed"]) - game["dirY"] * math.sin(-game["rotSpeed"])
		game["dirY"] = oldDirX * math.sin(-game["rotSpeed"]) + game["dirY"] * math.cos(-game["rotSpeed"])
		oldPlaneX = game["planeX"]
		game["planeX"] = game["planeX"] * math.cos(-game["rotSpeed"]) - game["planeY"] * math.sin(-game["rotSpeed"])
		game["planeY"] = oldPlaneX * math.sin(-game["rotSpeed"]) + game["planeY"] * math.cos(-game["rotSpeed"])
	if keys[pygame.K_e]:
		oldDirX = game["dirX"]
		game["dirX"] = game["dirX"] * math.cos(game["rotSpeed"]) - game["dirY"] * math.sin(game["rotSpeed"])
		game["dirY"] = oldDirX * math.sin(game["rotSpeed"]) + game["dirY"] * math.cos(game["rotSpeed"])
		oldPlaneX = game["planeX"]
		game["planeX"] = game["planeX"] * math.cos(game["rotSpeed"]) - game["planeY"] * math.sin(game["rotSpeed"])
		game["planeY"] = oldPlaneX * math.sin(game["rotSpeed"]) + game["planeY"] * math.cos(game["rotSpeed"])

	if keys[pygame.K_w]:
		if (map_table[int(player["posX"] + game["movSpeed"] * game["dirX"])][int(player["posY"])] == 0):
			player["posX"] += game["movSpeed"] * game["dirX"]
		if (map_table[int(player["posX"])][int(player["posY"] + game["movSpeed"] * game["dirY"])] == 0):
			player["posY"] += game["movSpeed"] * game["dirY"]
	if keys[pygame.K_s]:
		if (map_table[int(player["posX"] - game["movSpeed"] * game["dirX"])][int(player["posY"])] == 0):
			player["posX"] -= game["movSpeed"] * game["dirX"]
		if (map_table[int(player["posX"])][int(player["posY"] - game["movSpeed"] * game["dirY"])] == 0):
			player["posY"] -= game["movSpeed"] * game["dirY"]
	if keys[pygame.K_a]:
		if (map_table[int(player["posX"] - game["movSpeed"] * game["planeX"])][int(player["posY"])] == 0):
			player["posX"] -= game["movSpeed"] * game["planeX"]
		if (map_table[int(player["posX"])][int(player["posY"] - game["movSpeed"] * game["planeY"])] == 0):
			player["posY"] -= game["movSpeed"] * game["planeY"]
	if keys[pygame.K_d]:
		if (map_table[int(player["posX"] + game["movSpeed"] * game["planeX"])][int(player["posY"])] == 0):
			player["posX"] += game["movSpeed"] * game["planeX"]
		if (map_table[int(player["posX"])][int(player["posY"] + game["movSpeed"] * game["planeY"])] == 0):
			player["posY"] += game["movSpeed"] * game["planeY"]

# def normalized(game):
	# game["x"] = round(game["x"], 1)
	# game["y"] = round(game["y"], 1)
	# game["dx"] = round(game["dx"], 1)
	# game["dy"] = round(game["dy"], 1)

def main():
	sw = 1280
	sh = 720
	map_table = [
		[1,1,1,1,1,1,1,1,1,1,1,1],
		[1,0,0,1,0,0,0,0,0,0,0,1],
		[1,0,0,1,0,0,0,0,0,0,0,1],
		[1,0,0,0,0,0,0,0,0,0,0,1],
		[1,0,0,0,0,0,0,0,0,0,0,1],
		[1,0,0,0,0,0,1,0,0,0,0,1],
		[1,0,0,0,0,0,0,0,0,0,0,1],
		[1,0,0,0,0,0,0,0,0,0,0,1],
		[1,0,0,0,0,0,0,0,0,0,0,1],
		[1,0,0,0,0,0,0,0,0,0,0,1],
		[1,1,1,1,1,1,1,1,1,1,1,1],
	]

	pygame.init()
	game = {
			"map": map_table,
			"running": True,
			"screen": pygame.display.set_mode((sw, sh)),
			"clock": pygame.time.Clock(),
			"height": len(map_table),
			"width": len(map_table[0]),
			"sheight": sh,
			"swidth": sw,
			"dt": 0.0,
			"movSpeed": 0.1,
			"rotSpeed": 0.1,
			"planeX": 0,
			"planeY": 0.66,
			"posX": 2.0,
			"posY": 2.0,
			"dirX": 1,
			"dirY": 0,
			}
	while game["running"]:

		game["screen"].fill("black")
		pygame.draw.rect(game["screen"], [255, 100, 100], pygame.Rect(0, 0, game["swidth"], game["sheight"] // 2))

		key_hook(game)

		# normalized(game)


		launch_ray(game)

		pygame.display.flip()

		game["dt"] = game["clock"].tick(60) / 1000.0

		# print(int(1.0 / game["dt"]))
		# print(f"{game["dirX"]} {game["dirY"]}")

if __name__ == "__main__":
	main()
