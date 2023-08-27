from .interface.interface import InterfaceBase
from .adapter.adapter import AdapterBase


class Client:
    def __init__(self) -> None:
        self._interface = None
        self._adapter = None

    @property
    def interface(self) -> InterfaceBase:
        return self._interface

    @interface.setter
    def interface(self, interface: InterfaceBase) -> None:
        self._interface = interface

    @property
    def adapter(self) -> AdapterBase:
        return self._adapter

    @adapter.setter
    def adapter(self, adapter: AdapterBase) -> None:
        self._adapter = adapter

    def Add(self, action) -> int:
        request = self._adapter.SerializeAction(action)
        response = self._serialize_and_send(request)
        return response.action_id

    def Remove(self, action_id: int):
        request = self._adapter.SerializeRemove(action_id)
        self._serialize_and_send(request)

    def GetStatus(self, action_id: int):
        request = self._adapter.SerializeStatus(action_id)
        response = self._serialize_and_send(request)
        return response.status

    def GetResult(self, action_id: int):
        request = self._adapter.SerializeResult(action_id)
        response = self._serialize_and_send(request)
        return response.result

    def _serialize_and_send(self, request):
        request_msg = self._adapter.Serialize(request)
        response_msg = self._interface.SendAndRecieve(request_msg)
        response = self._adapter.Parse(response_msg)
        return response
