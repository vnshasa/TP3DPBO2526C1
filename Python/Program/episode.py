class Episode:
    """
    Satu episode dalam sebuah Drama.
    Episode adalah "part of" Drama (Composition) -> disimpan sebagai bagian dari Drama.
    """

    def __init__(self, number: int, title: str, duration_minutes: int, viewer_rating: float):
        self.__number = number
        self.__title = title
        self.__duration_minutes = duration_minutes
        self.__viewer_rating = viewer_rating

    # ---------- Getter ----------
    def get_number(self) -> int:
        return self.__number

    def get_title(self) -> str:
        return self.__title

    def get_duration_minutes(self) -> int:
        return self.__duration_minutes

    def get_viewer_rating(self) -> float:
        return self.__viewer_rating

    # ---------- Setter ----------
    def set_number(self, number: int) -> None:
        self.__number = number

    def set_title(self, title: str) -> None:
        self.__title = title

    def set_duration_minutes(self, duration_minutes: int) -> None:
        self.__duration_minutes = duration_minutes

    def set_viewer_rating(self, viewer_rating: float) -> None:
        self.__viewer_rating = viewer_rating

    def display(self) -> None:
        print(f"    {self.__number:>2} | {self.__title:<50} | "
              f"{self.__duration_minutes:>3} menit | {self.__viewer_rating:>5.1f}%")
