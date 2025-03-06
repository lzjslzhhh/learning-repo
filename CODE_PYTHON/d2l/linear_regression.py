import random
from torch.utils.data import TensorDataset
import torch

true_w = torch.tensor([2, -3.4])
true_b = torch.tensor([4.2])


def synthetic_data(w, b, num_examples):
    X = torch.normal(0, 1, (num_examples, len(w)))
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))


features, labels = synthetic_data(true_w, true_b, 1000)


def data_iter(features, labels, batch_size):
    num_examples = len(features)
    indices = list(range(num_examples))
    random.shuffle(indices)
    for i in range(0, num_examples, batch_size):
        batch_indices = torch.tensor(indices[i:min(i + batch_size, num_examples)])
        yield features[batch_indices], labels[batch_indices]


batch_size = 10

# for X, y in data_iter(features, labels, batch_size):
#     print(X, '\n', y)
#     break

w = torch.normal(0, 0.01, size=(2, 1), requires_grad=True)
b = torch.zeros(1, requires_grad=True)


def linear_regression(X, w, b):
    return torch.matmul(X, w) + b


def square_loss(y_hat, y):
    return (y_hat - y.reshape(y_hat.shape)) ** 2 / 2


def sgd(params, lr, batch_size):
    with torch.no_grad():
        for param in params:
            param -= lr * param.grad / batch_size
            param.grad.zero_()


lr = 0.03
num_epochs = 3
net = linear_regression
loss = square_loss

for epoch in range(num_epochs):
    for X, y in data_iter(features, labels, batch_size):
        l = loss(net(X, w, b), y)
        l.sum().backward()
        sgd([w, b], lr, batch_size)
    with torch.no_grad():
        train_loss = loss(net(features, w, b), labels)
        print(f'epoch{epoch + 1}, loss={float(train_loss.mean()):f}')

print(true_w - w.reshape(true_w.shape))
print(true_b - b)
