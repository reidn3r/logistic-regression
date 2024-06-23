from src.MLModel import LogisticRegression
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.datasets import load_breast_cancer

def load_dataset():
    data = load_breast_cancer()
    X, y = data.data, data.target
    return X, y

def split(X, y, test_size=0.2):
    scaler = StandardScaler()
    X = scaler.fit_transform(X)
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=test_size, random_state=42)
    return X_train, X_test, y_train, y_test

def main():
    X, y = load_dataset()
    X_train, X_test, y_train, y_test = split(X, y, 0.2)

    model = LogisticRegression()
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    y_pred_binary = (y_pred > 0.5).astype(int)

    accuracy = accuracy_score(y_test, y_pred_binary)
    print(f'Acurácia do modelo: {accuracy:.2f}')
    return;


if __name__ == "__main__":
    main()