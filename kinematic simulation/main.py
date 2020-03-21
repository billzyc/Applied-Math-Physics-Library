from ball import Ball
from grid import Grid
import pygame
import math

environment = {
    "xResistance": 0,
    "yResistance": -9.81
}

window = {
  "width": 800,
  "height": 800
}

def calculateLocation(currentGrid, currentBall,secondsPassed):
    x =  currentGrid.initialX + currentGrid.positionKinematicFormula(currentBall.initialVelocityX, secondsPassed, environment['xResistance'])
    y = currentGrid.initialY - currentGrid.positionKinematicFormula(currentBall.initialVelocityY, secondsPassed, environment['yResistance'])
    currentGrid.x = x
    currentGrid.y = y
    # print(f"current position - x: {x} y: {y} at {pygame.time.get_ticks()}")


def timeToGround( location, velocity, acceleration):
    a = acceleration / 2
    b = velocity
    c = location
    root = math.sqrt(b**2 - 4 * a * c);
    return abs((-b - root) / (2 * a));

simulatedBall = Ball()
location = Grid()
location.getHeight()
getBallCondition = input("add initial velocity and initial degree? Input y for yes, any key for no: ")
if(getBallCondition == 'y'):
    simulatedBall.getBallConditions()

pygame.init()
win = pygame.display.set_mode((window["width"],window["height"]))
pygame.display.set_caption("kinematics simulation")
run = True
while run:
  #   simulatedBall.calculateCurrentVelocity(pygame.time.get_ticks()/1000, environment['xResistance'], environment['yResistance'])
  if(location.y > 0):
    calculateLocation(location, simulatedBall, pygame.time.get_ticks()/1000)
    # print(pygame.time.get_ticks()/100, location.y)
    # print( f" at {pygame.time.get_ticks()/100} seconds" )
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      run = False
  pygame.draw.rect(win, (255, 0, 0), (location.x, location.y, 5, 5))
  pygame.display.update()
  win.fill((0,0,0))
pygame.quit()