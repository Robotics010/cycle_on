import argparse

from settings.reader import Reader as ConfigReader
from settings.json import Json as JsonConfig
from network.client import Client
from network.interface.tcp.client import Client as TcpClient
from network.adapter.json_over_tcp import JsonOverTcp as JsonTcpAdapter


def process(args):
    config_reader = ConfigReader()
    config_reader.implementation = JsonConfig()
    config = config_reader.Open(args.config)

    client = Client()
    client.interface = TcpClient(
        address=config.network.address,
        port=config.network.port)
    client.adapter = JsonTcpAdapter()

    # ToDo: add low-level client cmd execute
    # action_id = client.Add(action)
    # client.Remove(action_id)
    # status = client.GetStatus(action_id)
    # result = client.GetResult(action_id)

    # ToDo: add high-level scenario group execution


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('config', help='path to config file')
    args = parser.parse_args()

    process(args)


if __name__ == '__main__':
    main()
