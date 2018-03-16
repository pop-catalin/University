class ValidatorException(Exception):
    def __init__(self, messageList =["Validation error"]):
        self._messageList = messageList

    def getMessage(self):
        return self._messageList

    def __str__(self):
        x = ""
        for message in self.getMessage():
            x += message
            x += '\n'
        return x