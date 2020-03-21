class Grid:

  def __init__(self):
    self.initialX = 50
    self.initialY = 0
    self.x = 50
    self.y = 0
    
  def getHeight(self):
    initialHeight = 800 - int(input("enter the height of the initial ball in meters: "))
    self.initialY = initialHeight
    self.y = self.initialY

  def positionKinematicFormula (self, initialVelocity, time, acceleration):
    return ((initialVelocity * time) + (acceleration * time * time / 2))

