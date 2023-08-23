from .implementation import Implementation
import json


class Json(Implementation):
    def Open(self):
        with open(self._path) as f:
            self._data = json.load(f)

    def getValue(self, key):
        return self._data[key]
