class Paddle:
    def __init__(self, width, height, x, table_height, speed):
        self.width2 = width / 2
        self.height2 = height / 2
        self.x = x
        self.y = 0
        self.speed = speed
        self.table_height = table_height

    def can_move_paddle(self, movement):
        top_limit = -(self.table_height / 2) + self.width2
        bottom_limit = self.table_lenght / 2 - self.width2
        return (top_limit <= self.y + (movement * self.speed) <= bottom_limit)

    def move_paddle(self, movement):
        if (self.can_move_paddle(self.speed * -1)):
            self.y += self.speed * movement

    def reset(self):
        self.y = 0

    def is_betwen_paddle_width(self, ball_x):
        return (self.x - self.width2 <= ball_x <= self.x + self.width2)

    def is_betwen_paddle_height(self, ball_y):
        return (self.y - self.height2 <= ball_y <= self.y + self.height2)

    def left_colision(self, ball_x, ball_y):
        return (
           ball_x >= self.x - self.width2
           and self.is_betwen_paddle_height(ball_y)
        )

    def right_colision(self, ball_x, ball_y):
        return (
           ball_x <= self.x + self.width2
           and self.is_betwen_paddle_height(ball_y)
        )

    def top_colision(self, ball_x, ball_y):
        return (
            ball_y >= self.y - self.height2
            and self.is_betwen_paddle_width(ball_x)
        )

    def bottom_colision(self, ball_x, ball_y):
        return (
            ball_y <= self.y + self.height2
            and self.is_betwen_paddle_width(ball_x)
        )


class Ball:
    def __init__(self, radio, speed):
        self.radio = radio
        self.x = 0
        self.y = 0
        self.dx = 1
        self.dy = 1
        self.speed = speed

    def move(self):
        self.x += self.dx * self.speed
        self.y += self.dy * self.speed

    def vertical_colision(self):
        self.dx *= -1

    def horizontal_colision(self):
        self.dy *= -1

    def get_ball_position(self):
        return self.x, self.y

    def gol(self):
        self.x = 0
        self.y = 0
        self.dx *= -1


