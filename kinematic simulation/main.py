from ball import Ball
from grid import Grid
import pygame
import math
import windowInfo

environment = {
    "xResistance": 0,
    "yResistance": -9.81
}


def timeToGround( location, velocity, acceleration):
    a = acceleration / 2
    b = velocity
    c = location
    root = math.sqrt(b**2 - 4 * a * c);
    return abs((-b - root) / (2 * a));

simulatedBall = Ball(5)
location = Grid()
location.getHeight()
getBallCondition = input("add initial velocity and initial degree? Input y for yes, any key for no: ")
if(getBallCondition == 'y'):
    simulatedBall.getBallConditions()

pygame.init()
win = pygame.display.set_mode((windowInfo.width, windowInfo.height))
pygame.display.set_caption("kinematics simulation")
run = True
while run:
  #   simulatedBall.calculateCurrentVelocity(pygame.time.get_ticks()/1000, environment['xResistance'], environment['yResistance'])
  if(location.y < windowInfo.groundHeight - simulatedBall.width):
    location.calculateLocation(simulatedBall, pygame.time.get_ticks()/1000, environment)
    # print(pygame.time.get_ticks()/100, location.y)
    # print( f" at {pygame.time.get_ticks()/100} seconds" )
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      run = False
  pygame.draw.line(win, (0,0,0), (0, windowInfo.groundHeight),(windowInfo.width,windowInfo.groundHeight))
  pygame.draw.rect(win, (0, 0, 0), (location.x, location.y, simulatedBall.width, simulatedBall.width))
  pygame.display.update()
  win.fill((255,255,255))
pygame.quit()