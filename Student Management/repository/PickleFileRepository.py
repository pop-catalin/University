from repository.Repository import Repository
import pickle

class PickleFileRepository(Repository):
    def __init__(self,fileName = "repo.pickle"):
        Repository.__init__(self)
        self.__fName = fileName
        self.__loadFromFile()

    def store(self, obj):
        Repository.store(self, obj)
        self.__storeToFile()

    def delete(self, objId):
        Repository.delete(self, objId)
        self.__storeToFile()

    def update(self, obj):
        Repository.update(self, obj)
        self.__storeToFile()

    def __loadFromFile(self):
        f = open(self.__fName, "rb")
        try:
            self._objects = pickle.load(f)
        except EOFError:
            self._objects = []
        except Exception as e:
            raise e
        finally:
            f.close()

    def __storeToFile(self):
        f = open(self.__fName, "wb")
        pickle.dump(self._objects, f)
        f.close()