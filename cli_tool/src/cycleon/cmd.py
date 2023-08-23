import argparse

from config.config import Config
from config.json import Json


def process(args):
    config = Config(args.config)
    config.implementation = Json()
    config.Open()
    address = config.getValue('address')
    port = config.getValue('port')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('config', help='path to config file')
    args = parser.parse_args()

    process(args)


if __name__ == '__main__':
    main()
