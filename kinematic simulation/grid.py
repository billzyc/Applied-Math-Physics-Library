import windowInfo
class Grid:

  def __init__(self):
    self.initialX = 50
    self.initialY = 0
    self.x = 50
    self.y = 0
    
  def getHeight(self):
    initialHeight = windowInfo.height - int(input("enter the height of the initial ball in meters: "))
    self.initialY = initialHeight
    self.y = self.initialY

  def positionKinematicFormula (self, initialVelocity, time, acceleration):
    return ((initialVelocity * time) + (acceleration * time * time / 2))

  def calculateLocation(self, currentBall, secondsPassed, environment):
    x =  self.initialX + self.positionKinematicFormula(currentBall.initialVelocityX, secondsPassed, environment['xResistance'])
    y = self.initialY - self.positionKinematicFormula(currentBall.initialVelocityY, secondsPassed, environment['yResistance'])
    self.x = x
    self.y = y