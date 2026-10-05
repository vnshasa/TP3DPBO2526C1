class Person:
    """
    BASE CLASS pada Hierarchical Inheritance.
    Actor, Director, dan Writer sama-sama mewarisi kelas ini.
    """

    def __init__(self, name: str, age: int, debut_year: int):
        self.__name = name
        self.__age = age
        self.__debut_year = debut_year

    # ---------- Getter ----------
    def get_name(self) -> str:
        return self.__name

    def get_age(self) -> int:
        return self.__age

    def get_debut_year(self) -> int:
        return self.__debut_year

    # ---------- Setter ----------
    def set_name(self, name: str) -> None:
        self.__name = name

    def set_age(self, age: int) -> None:
        self.__age = age

    def set_debut_year(self, debut_year: int) -> None:
        self.__debut_year = debut_year
    def get_role(self) -> str:
        return "Person"

    def display_info(self) -> None:
        print(f"  * [{self.get_role()}] {self.__name}")
        print(f"      Umur / Debut : {self.__age} tahun / debut {self.__debut_year}")
