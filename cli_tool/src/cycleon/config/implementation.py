from abc import ABC, abstractmethod


class Implementation(ABC):
    @property
    def path(self):
        return self._path

    @path.setter
    def path(self, path) -> None:
        self._path = path

    @abstractmethod
    def Open(self):
        ...

    @abstractmethod
    def getValue(self, key):
        ...
