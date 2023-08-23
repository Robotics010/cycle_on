import os
import sys

sys.path.append(os.path.join(os.getcwd(), 'src', 'cycleon'))  # nopep8
from config.config import Config  # nopep8
from config.json import Json  # nopep8


def test_read_json_config():
    config_path = 'test/data/config_test.json'
    config = Config(config_path)
    config.implementation = Json()
    config.Open()

    assert config.getValue("index") == 12
    assert config.getValue("pi") == 3.141
    assert config.getValue("hello") == "World"
    assert config.getValue("happy") == True
