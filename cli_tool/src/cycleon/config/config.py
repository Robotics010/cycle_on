from .implementation import Implementation


class Config:
    def __init__(self, path) -> None:
        self._path = path
        self._implementation = None

    @property
    def implementation(self) -> Implementation:
        return self._implementation

    @implementation.setter
    def implementation(self, implementation: Implementation) -> None:
        self._implementation = implementation
        self._implementation.path = self._path

    def Open(self):
        self._implementation.Open()

    def getValue(self, key):
        return self._implementation.getValue(key)
